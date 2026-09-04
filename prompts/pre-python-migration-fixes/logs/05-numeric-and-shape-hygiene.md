# Log 05 — Numeric and expression-shape hygiene

**Prompt:** `prompts/pre-python-migration-fixes/05-numeric-and-shape-hygiene.md`
**Executed:** 2026-09-04
**Branch:** `pre-python-migration-fixes/05-numeric-and-shape-hygiene`
**Commit:** *(recorded after commit; see `IMPLEMENTATION_STATE.md`)*
**Parent commit:** `8d72e7e` (prompt 04 complete)
**Status:** Complete

---

## 1. What this prompt was for

Three independent, cheap fixes that convert *silently wrong* into *correct* or into *loudly
stops*, none of which is expected to change a single emitted number on the current operator
basis: (1) replace the unsigned-integer `A(r)` (Neumann–Adams coefficient) with its exact closed
form, removing a silent overflow at r ≥ 11 and an accidental ~2×10⁹-iteration loop at r = 0; (2)
guard `double_factorial(num-1)` against `num == 0`, which would otherwise underflow to
`double_factorial(SIZE_MAX)` — a hang; (3) unify three separate hand-rolled destructurings of a
GiNaC product (each of which silently mishandles a shape it does not recognise) into one shared
factor-enumeration helper that raises on anything genuinely unhandled.

## 2. What was changed

| File | Change | Notes |
|---|---|---|
| `lib/one_loop_reduced_integral.cpp` | `A(unsigned int r)`: replaced the two `while` loops (numerator = (2r-1)!!, denominator = r!, both in `unsigned int`) with `GiNaC::binomial(numeric,numeric) / GiNaC::pow(numeric,numeric)`, i.e. `C(2r,r)/2^r` | Fix 1 |
| `lib/one_loop_reduced_integral.cpp` | New `one_loop_reduced_integral::extract_Legendre_factors(term, var, partner_q)`: the shared factor-enumeration helper (see §2.2 below) | Fix 3 |
| `lib/one_loop_reduced_integral.cpp` | `apply_Legendre_orthogonality(expr, q)` (zero-Rayleigh): body replaced by a shape guard (throws `ERROR_BADLY_FORMED_LEGENDRE_SUM_TERM` on anything not in {mul, numeric, power, symbol, function}) followed by one call to `extract_Legendre_factors`; downstream logic (the `partner_q.size()` case analysis) unchanged | Fix 3, site 2 |
| `lib/one_loop_reduced_integral.cpp` | `apply_Legendre_orthogonality(expr, L, Lcoeff, k, kcoeff, R)` (one-Rayleigh): same treatment — a shape guard was added (there was none before) followed by one call to `extract_Legendre_factors`; downstream logic unchanged | Fix 3, site 3 |
| `lib/one_loop_reduced_integral.h` | `integrate_Legendre`: the `if(is_a<symbol> \|\| is_a<function>) return term;` pass-through removed; those two classes are now included in the same branch as mul/numeric/power, all three forwarded uniformly to `f()` | Fix 3, site 1 |
| `lib/one_loop_reduced_integral.h` | New private declarations: `using Legendre_list = std::vector<std::pair<GiNaC::symbol, unsigned int>>;` (hoisted out of the two functions that used to declare it locally and identically) and `static GiNaC::ex extract_Legendre_factors(...)` | Fix 3 |
| `utilities/GiNaC_utils.cpp` / `.h` | `to_exvector(expr)`: now returns a one-element vector `{expr}` for any non-`mul` input, instead of decomposing via `expr.nops()` (which is wrong for numeric/symbol [drops the value: `nops()==0`] and for power [splits into base+exponent: `nops()==2`]) | Extends an existing shared utility; see §3.2 D-1 |
| `lib/detail/contractions.cpp` | `enumerate_contractions`: added `if(num == 0) throw exception(ERROR_ZERO_FIELD_CONTRACTIONS, ...)` immediately before the `double_factorial(num-1)` call | Fix 2 |
| `lib/detail/contractions.cpp` | `double_factorial`: added `assert(N != std::numeric_limits<size_t>::max() && "...")` at entry; added `#include <cassert>`, `#include <limits>` | Fix 2, defensive extra (see §7 — compiled out in the shipped Release build) |
| `localizations/en/messages_en.h` | New constant `ERROR_ZERO_FIELD_CONTRACTIONS = "Cannot enumerate contractions of an empty field set";`, placed immediately after `ERROR_ODD_CONTRACTIONS` | Fix 2 |

New files:

| File | Purpose |
|---|---|
| `validation/test_neumann_adams.cpp` | Standalone regression test pinning `A(0..20)` (see §3.2 D-2 for why it is standalone rather than linked against the built binary, and §4 for how it is run) |

Deleted files: none.

### 2.1 `extract_Legendre_factors`, in detail

```cpp
GiNaC::ex
one_loop_reduced_integral::extract_Legendre_factors(const GiNaC::ex& term, const GiNaC::symbol& var,
                                                    Legendre_list& partner_q)
```

Given `term` (guaranteed by the caller to be one of the five shapes `integrate_Legendre`
recognises: `mul`, `numeric`, `power`, `symbol`, `function`) and the reduction variable `var`
(`q` at site 2, `L` at site 3), it:

1. Calls `to_exvector(term)` to get a uniform factor list — one element for anything that is not
   itself a `mul`.
2. For each factor: if it is a `power` whose exponent is a positive integer *m*, records the
   candidate as (base, multiplicity = m); otherwise (bare factor) records (factor, multiplicity = 1).
3. If the candidate is not a `LegP` function, the *original* factor (power or bare) is multiplied
   into `temp`, unchanged.
4. If it is a `LegP(n, p1, p2)` and neither `p1` nor `p2` equals `var`, the original factor is
   likewise multiplied into `temp` — a Legendre polynomial not involving the reduction variable is
   not something the orthogonality relation below can use.
5. Otherwise, `multiplicity` copies of `(partner, n)` are appended to `partner_q`, where `partner`
   is whichever of `p1`/`p2` is not `var`.

Step 2+5 together are what makes `LegP(n, var, p)**2` register as *two* entries of `(p, n)` in
`partner_q`, rather than as one opaque `power` swept into `temp` (the zero-Rayleigh site's old
behaviour) or destructured into `LegP(...)` and `2` as if they were independent multiplicative
factors (what the one-Rayleigh site's *lack* of any shape check would have done, had it ever been
exercised on this shape — see §2.2).

### 2.2 The three sites, before and after

| Site | Before | After |
|---|---|---|
| `integrate_Legendre` (`.h`) | A bare `symbol`/`function` term was returned **unintegrated** (`return term;`) — no 4π normalisation, no orthogonality zeroing | Forwarded to `f()` in the same branch as mul/numeric/power; `f()` (one of the two `apply_Legendre_orthogonality` overloads) now handles it correctly via `extract_Legendre_factors` |
| `apply_Legendre_orthogonality(expr, q)` (zero-Rayleigh) | `is_a<numeric> \|\| is_a<power>` unconditionally set `temp = expr` as a whole — a `power` whose base was `LegP(n,q,k)` (i.e. `LegP(n,q,k)**2`) was swept whole into the 4π prefactor instead of being reduced by orthogonality | `extract_Legendre_factors` inspects every factor uniformly (including inside a bare `power`), so a power-of-`LegP` is unfolded and handled correctly regardless of whether it arrived bare or inside a `mul` |
| `apply_Legendre_orthogonality(expr, L, Lcoeff, k, kcoeff, R)` (one-Rayleigh) | **No shape check at all**: iterated `expr.op(i)` unconditionally. `nops()==0` for a `numeric` silently dropped the coefficient (loop body never executes, `temp` stays 1); `nops()==2` for a `power` destructured it into `(base, exponent)` as two independent "factors" (`R**-2` → `R`, `-2`) | Same shape guard as site 2, then `extract_Legendre_factors`, which treats a bare `numeric`/`power` as a single factor (not decomposed via `nops()`) |

## 3. Divergences from the prompt

### 3.1 Structurally required

None. All three fixes match the prompt's prescription; nothing in the codebase forced a
different shape from what was asked.

### 3.2 Implementation choices

> **D-1 — where the shared factor-list helper lives: two layers, not one**
> **Prompt asked:** "All three sites use one shared helper to enumerate factors" and asked for a
> decision between `utilities/GiNaC_utils` vs. a new file vs. a private static in
> `one_loop_reduced_integral.cpp`.
> **Shipped:** two layers. (a) `utilities/GiNaC_utils::to_exvector` was extended (not
> reimplemented) to behave like `SymPy`'s `Mul.make_args` for a non-`mul` argument — this is the
> project's existing, general-purpose "decompose a product" utility, already used by
> `lib/detail/legendre_utils.cpp`'s `dot_products_to_cos_impl::convert_mul`. (b) A new private
> static method, `one_loop_reduced_integral::extract_Legendre_factors`, layers the
> Legendre-specific logic (LegP detection, partner-symbol matching, multiplicity unfolding) on top
> of `to_exvector`, and is the one function all three sites now share.
> **Options considered:** (i) put the whole thing (generic decomposition + LegP matching) in one
> new free function in `utilities/GiNaC_utils`; (ii) put the whole thing in one new private static
> in `one_loop_reduced_integral`, reimplementing factor decomposition locally rather than reusing
> `to_exvector`; (iii) the two-layer split that was shipped.
> **Criterion used:** `to_exvector` already existed, was already used elsewhere for exactly
> "decompose a product into factors", and its bug (assuming its argument is always a `mul`) is a
> defect in its own right, independent of the Legendre sites — fixing it in place both serves this
> prompt and improves a general-purpose utility for any future caller. The LegP-specific matching
> (order, partner symbol, multiplicity, the four exception constants) has no purpose outside
> `one_loop_reduced_integral` and would be a strange addition to a header that otherwise has no
> knowledge of `LegP`, Legendre orthogonality, or Rayleigh momenta.
> **Trade-off a later reader might weigh differently:** a single-layer helper wholly inside
> `one_loop_reduced_integral.cpp` would keep every line of this fix in one file, at the cost of
> duplicating (or not fixing) `to_exvector`'s existing defect. Given that `to_exvector` is called
> exactly once elsewhere, and only ever with a confirmed `mul` argument (verified in §3.2 D-1's own
> checking, not asserted from memory — see `lib/detail/legendre_utils.cpp`'s `convert()` dispatcher,
> which only calls `convert_mul` after `is_a<mul>(expr)`), extending it is behaviour-preserving for
> that caller and was judged the smaller, more useful change.

> **D-2 — `validation/test_neumann_adams.cpp` reimplements the closed form rather than linking
> against the built `A()`**
> **Prompt asked:** "Add a self-contained check pinning A(0…20) against exact rationals. Suggested
> home: `validation/test_neumann_adams.cpp`, built by `validation/build.sh` as a separate small
> target, or a Python check that hard-codes the expected values. Either is fine — say which and
> why."
> **Shipped:** a standalone C++ file, in the same spirit as the existing
> `validation/ginac_ordering_probe.cpp` — compiled by hand with a documented one-line `c++`
> invocation, not wired into `validation/build.sh` or CMake. It re-expresses the exact closed-form
> expression used by the fixed `A()` (`GiNaC::binomial(numeric,numeric)/GiNaC::pow(numeric,numeric)`)
> and cross-checks it against 21 hand-reduced exact fractions independently derived from
> `C(2r,r)/2^r`.
> **Options considered:** (a) a CMake target that links a small test `main()` against a Python
> script or manually-listed subset of the project's compiled object files, so the test exercises
> the actual production `A()` rather than a copy of its expression; (b) a Python script hard-coding
> the expected values and comparing against nothing (no oracle) — rejected, it wouldn't exercise
> GiNaC at all; (c) the shipped standalone-reimplementation approach.
> **Why (a) was tried and abandoned:** `A(unsigned int)` is a free function with no header
> declaration, defined directly in `lib/one_loop_reduced_integral.cpp`. It has external linkage (it
> is not `static`/anonymous-namespace), so `extern GiNaC::numeric A(unsigned int);` plus linking
> against `lib/one_loop_reduced_integral.cpp.o` was attempted directly. This failed at link time:
> object files, unlike archives, are pulled into a link as a whole, so linking against that one `.o`
> also drags in every other member function defined in the same translation unit (the entire
> `one_loop_reduced_integral` reduction machinery), which in turn need `Legendre_to_cosines`,
> `cosines_to_Legendre`, `dot_products_to_cos`, `symbol_factory::make_symbol`,
> `argument_cache::get_symmetrize_22`, the `Angular::LegP`/`Fabrikant::FabJ` GiNaC function
> registrations, and more — effectively most of the rest of the project's object files. Linking
> against the full set of built `.o` files (all of them except `main.cpp.o`) was not attempted
> further because it would have meant adding a permanent CMake test target purely to exercise one
> pure function, which sits awkwardly against prompt 01's stated goal of keeping the build "only a
> C++17 compiler and `pkg-config ginac`" (a CMake *test* target would not violate that goal by
> itself, but it is more machinery than a 21-line arithmetic check needs).
> **Criterion used:** match the precedent already set in this directory
> (`validation/ginac_ordering_probe.cpp`) for a small, standalone, hand-built diagnostic that is
> not part of the reproducible build; avoid adding CMake surface area for a test whose entire
> subject is "does this closed-form arithmetic expression evaluate to the right exact rational",
> which does not require exercising the rest of the class.
> **Trade-off a later reader might weigh differently:** this test would not catch a regression
> where `A()`'s call site stopped using this closed form at all (e.g. someone reverting to the old
> loop) — it tests the *formula*, not that production code calls it. A future prompt with a real
> unit-test harness for this project could instead expose `A()` via a header declaration and link
> properly; that was judged out of scope for a hygiene prompt that is not supposed to add general
> testing infrastructure.

> **D-3 — the one-Rayleigh site's new shape guard reuses `ERROR_BADLY_FORMED_LEGENDRE_SUM_TERM`
> rather than a new constant**
> **Prompt asked (requirement 3):** "the existing throws ... must be preserved. Never fall through
> silently," without specifying whether a *new* shape check (site 3 previously had none at all)
> should get a new message or reuse an existing one.
> **Shipped:** reused `ERROR_BADLY_FORMED_LEGENDRE_SUM_TERM` (already used at site 2 for the
> identical situation: an `expr` outside the five recognised top-level shapes) for the new guard at
> site 3.
> **Options considered:** (a) reuse the existing constant (shipped); (b) mint a new constant
> specific to the one-Rayleigh call site.
> **Criterion used:** the two sites now guard against exactly the same condition (`expr` is not
> one of mul/numeric/power/symbol/function) using exactly the same message text
> ("Badly formed term in Legendre representation"), which is accurate at both sites; a second
> constant with the same wording would be a Fix-2-style near-duplicate (the thing prompt 05's own
> Fix 2 explicitly avoided doing with `ERROR_ODD_CONTRACTIONS`), and unlike Fix 2's case, the
> message is not misleading at the new site.
> **Trade-off a later reader might weigh differently:** the constant's name and existing few call
> sites are historically about the zero-Rayleigh reduction; a reader grepping for
> "one-Rayleigh"-specific error text will not find a dedicated symbol. This was judged acceptable
> since the message text itself is generic ("badly formed term"), not scoped to zero-Rayleigh.

### 3.3 Unintended drift

None. `git diff --stat` shows changes confined to the six files listed in §2 plus one new file;
no reformatting or unrelated edits were made. (Fix 3's edits necessarily touch large contiguous
blocks of `apply_Legendre_orthogonality`'s bodies because the whole per-factor loop was replaced,
not because of incidental whitespace normalisation — confirmed by reading the diff in §2 of this
log, reproduced verbatim from `git diff`.)

## 4. Verification

All commands were run against `validation/build.sh`'s default `-DCMAKE_BUILD_TYPE=Release` build
(`-O3 -DNDEBUG`), rebuilt from a clean `build-validation/` directory for the final numbers below
(Apple clang 21.0.0 arm64, GiNaC 1.8.10 + CLN 1.3.7 from MacPorts, CMake 3.31.11, macOS 26.5.2,
Apple M1 Pro — the same toolchain prompts 02–04 used).

| Check | Expected | Observed | Verdict |
|---|---|---|---|
| Build | clean at `-std=c++17` | clean; only the pre-existing CMake dev-warnings (`FindPackageHandleStandardArgs`, `BuildGiNaC.cmake` deprecation); zero compiler warnings from any project file, including all four changed | PASS |
| `A(0..20)` regression test | all 21 values exact, `A(11) == 88179/256` | `/tmp/test_neumann_adams`: **ALL PASSED (24 checks)** | PASS |
| Kernel count | 101 | 101 | PASS |
| `compute_*` name set | identical to baseline | md5 `2f419fdb9e8446488364180e66671acf`, identical to the value recorded in `logs/04-wick-tier1-fixes.md` §4 | PASS |
| Integrand signature multiset | identical to `baseline/pre-fix` | `compare_autogenerated.py`: **101 of 101 matched**, exit 0 | PASS |
| Counterterm map (canonicalised) | identical to baseline | byte-identical after header-strip, 0 diff lines | PASS |
| Warning set | identical to baseline (3) | 3 warnings, same text (`q0` momentum warning + two empty-`bG3`-filter warnings) | PASS |
| Dedup | 101 → 95, 6 pairs | **101 emitted, 95 distinct, 6 duplicate groups** (`ker2==ker8`, `ker3==ker9`, `ker33==ker74`, `ker47==ker69`, `ker48==ker73`, `ker70==ker72`) — identical pairing to prompt 04 | PASS |
| Textual diff of `autogenerated/` vs. the pre-prompt-05 tree (timestamp stripped) | expected empty (post-prompt-03 the tree is deterministic; this prompt should change nothing emitted) | **empty**: 0 diff lines across all 21 non-timestamp files | PASS |
| Functional equality vs. the 2018 reference tree | identical | 101/101 matched, `compute_*` identical at 135 names | PASS |
| Wall clock | ~43 s minus ~2 s (removing the `A(0)` loop) | see §5 — full-pipeline numbers are within prompt 02–04's already-measured 42.8–47.8 s noise band; the loop's cost was instead isolated with a microbenchmark | PASS, with the caveat recorded in §5 |

### 4.1 Exact commands

```bash
# --- A(r) regression test (standalone; see D-2) ---
c++ -std=c++17 -O2 $(pkg-config --cflags ginac) validation/test_neumann_adams.cpp \
    -o /tmp/test_neumann_adams $(pkg-config --libs ginac)
/tmp/test_neumann_adams
#  -> ALL PASSED (24 checks), exit 0

# --- clean build ---
rm -rf build-validation && ./validation/build.sh
#  -> clean, zero project warnings

# --- Legendre-site shape-distribution instrumentation (temporary; removed before commit, see §6) ---
rm -rf build-validation
cmake -S . -B build-validation -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-DLSSEFT_LEGENDRE_INSTRUMENT"
cmake --build build-validation --target LSSEFT_analytic -j"$(getconf _NPROCESSORS_ONLN)"
./validation/run.sh "$PWD/validation/out/instr-run"
tail -5 validation/out/instr-run.log
#  -> [LEGENDRE-INSTR] site1 (integrate_Legendre) top-level shape: mul=1508 numeric=20 power=0
#     symbol=0 function=0 add=1157 unhandled=0
#  -> [LEGENDRE-INSTR] site2 (zero-Rayleigh) top-level shape: mul=852 numeric=20 power=0 symbol=0
#     function=0 ; power-of-LegP factors seen=0
#  -> [LEGENDRE-INSTR] site3 (one-Rayleigh) top-level shape: mul=3063 numeric=0 power=0 symbol=0
#     function=0 ; power-of-LegP factors seen=0

# --- instrumentation removed; final clean build ---
rm -rf build-validation && ./validation/build.sh
./validation/run.sh "$PWD/validation/out/final"

# --- functional comparison vs baseline/pre-fix ---
python3 validation/compare_autogenerated.py --quiet \
  validation/out/final/autogenerated --signatures validation/baselines/pre-fix/signatures.json
#  -> 101 of 101 matched, exit 0

# --- compute_* name set ---
grep -o 'compute_[A-Za-z0-9_]*' validation/out/final/autogenerated/Pk_expressions.cpp \
  | sort -u | md5     # 2f419fdb9e8446488364180e66671acf -- matches baseline

# --- dedup ---
python3 validation/canonical_form.py --dedup --expect 101:95:6 validation/out/final/autogenerated
#  -> OK

# --- counterterm map, canonicalised ---
python3 validation/canonical_form.py --counterterm-map validation/out/final.log > /tmp/final_ct_canon.txt
diff <(tail -n +17 validation/baselines/pre-fix/counterterm-map.canonical.txt) /tmp/final_ct_canon.txt
#  -> no output (first 16 lines of the baseline file are a hand-written header, stripped before compare)

# --- 2018 reference comparison ---
python3 validation/compare_autogenerated.py --quiet \
  validation/out/final/autogenerated ~/Documents/Code/LSSEFT/autogenerated
#  -> 101 of 101 matched, compute_* identical at 135 names, exit 0

# --- textual diff, pre-prompt-05 tree vs. final (this repository, timestamp stripped) ---
for f in validation/out/before-fix/autogenerated/*.cpp; do
  bn=$(basename "$f"); [[ "$bn" == pipeline_id.cpp ]] && continue
  diff <(grep -v '^// Generated at' "$f") \
       <(grep -v '^// Generated at' "validation/out/final/autogenerated/$bn")
done
#  -> no output at all: zero differences across all 21 files
```

## 5. Behaviour that intentionally changed

**Nothing in the emitted `autogenerated/` tree.** Verified, not assumed (§4): the tree is
byte-identical (timestamp excepted) to the pre-prompt-05 tree, and functionally identical to both
`baseline/pre-fix` and the 2018 reference. This matches the prompt's own expectation — none of the
three previously-dead branches this prompt fixes is reached on the current operator basis (§4.1's
instrumentation numbers, and see §6 below).

**Wall clock — the one number the prompt explicitly said would change, and the one place this
log's measurement disagrees with the prompt's:**

The prompt, following the study, quotes the r = 0 loop's cost as "2.2 s at -O1" and asks the log
to "report both numbers" for a full-pipeline run. Measuring the isolated call directly (not
embedded in a 45 s run, where it would be swamped by noise) gives:

| Build flags | `A_old(0)` (unsigned-int loop) | `A_new(0)` (closed form) |
|---|---|---|
| `-O1` | 2.108 s | 0.000024 s |
| `-O2` | 0.133 s | 0.000015 s |
| `-O3 -DNDEBUG` (**this project's actual release flags**, confirmed from `build-validation/CMakeFiles/LSSEFT_analytic.dir/flags.make`) | 0.131 s | 0.000539 s |

The study's 2.2 s figure is specific to `-O1`; at the flags this project actually builds with
(`-O3 -DNDEBUG`, set by CMake's `Release` build type with no project override), the old loop cost
was **~0.13 s**, not ~2 s. Both are eliminated by the closed form. A full-pipeline before/after
comparison was also run directly (not merely inferred from the microbenchmark):

| Run | User CPU | Wall |
|---|---|---|
| Before (old `A(r)`, checked out via `git show HEAD:...` — see below) | 46.20 s | 61.0 s |
| After (this prompt's fix), run 1 | 45.97 s | 54.5 s |
| After (this prompt's fix), run 2 | 46.98 s | 63.7 s |

All three are within the 42.8–47.8 s user-CPU noise band already measured across prompts 02–04
(background system load dominates; prompt 04's log recorded a 53.17 s outlier at 57% CPU on the
same machine). The ~0.13 s saving is real (confirmed by the isolated microbenchmark above) but is
not visible against that noise floor in a full run — which is exactly why the microbenchmark, not
the full-pipeline timing, is the number to trust here. **Method used for the "before" run:**
`git show HEAD:lib/one_loop_reduced_integral.cpp` was written out over the working file, rebuilt,
timed, and then the working file was restored from a copy taken beforehand and rebuilt again;
`git status` was clean immediately before and after.

## 6. Shape distribution at the three Legendre sites (instrumented, then removed)

Temporary instrumentation (`#ifdef LSSEFT_LEGENDRE_INSTRUMENT`, built with
`-DLSSEFT_LEGENDRE_INSTRUMENT` passed via `CMAKE_CXX_FLAGS`, never checked into the committed
source — confirmed by `grep -n "LSSEFT_LEGENDRE_INSTRUMENT\|g_legendre_instr"
lib/one_loop_reduced_integral.{h,cpp}` returning no matches in the shipped tree) counted, over one
full canonical run (`--no-auto-symmetrize --symmetrize-22 --counterterms`), how many times each
top-level GiNaC expression class reached each of the three sites:

| Site | mul | numeric | power | symbol | function | add | power-of-`LegP` factors | unhandled |
|---|---|---|---|---|---|---|---|---|
| 1 — `integrate_Legendre` | 1508 | 20 | 0 | 0 | 0 | 1157 | — | 0 |
| 2 — zero-Rayleigh `apply_Legendre_orthogonality` | 852 | 20 | 0 | 0 | 0 | — | 0 | — |
| 3 — one-Rayleigh `apply_Legendre_orthogonality` | 3063 | 0 | 0 | 0 | 0 | — | 0 | — |

**Confirms the study's claim exactly:** every previously-dead branch this prompt fixes remains
untaken on the current operator basis. No top-level `power`, bare `symbol`, or bare `function`
ever reaches any of the three sites; no `power`-of-`LegP` factor is ever seen inside a `mul`
either. Site 1's `unhandled=0` also confirms the pre-existing
`ERROR_BADLY_FORMED_TOP_LEVEL_LEGENDRE_SUM` throw was not newly triggered by widening its first
branch to include symbol/function. This is consistent with the byte-identical output in §4: if a
previously-dead branch had fired even once with a different result from the old code, the emitted
tree could not be byte-identical.

**Not done:** the prompt's *optional* suggestion to also unit-test the new
`extract_Legendre_factors` helper directly on hand-built expressions
(`LegP(2,q,k)`, `LegP(2,q,k)**2`, `3*LegP(2,q,k)`, `GiNaC::numeric(5)`, a bare symbol, `R**-2`).
`extract_Legendre_factors` is a `protected static` member of `one_loop_reduced_integral`, so
exercising it from a standalone test file would require either weakening its access specifier
(for no other reason than testability) or a friend/derived-class shim purely to expose it. Given
that (a) it is optional in the prompt, (b) the instrumentation above already demonstrates its
input distribution on real data, and (c) the byte-identical-output check in §4 is a strong global
regression test, this was judged not worth adding new test-only surface area to the class for.
Recorded here as a deliberate omission, not an oversight, per the working agreement's "silence is
not an option" rule.

## 7. Issues opened, closed or updated

| ID | Action | Detail |
|---|---|---|
| I-08 | **Closed** | "`A(r)`'s denominator overflows at r = 13 as well as the numerator at r = 11. Both go away with the closed form." Confirmed exactly: the old code's `A(11)` evaluates to `21.655260116...` (wrong; correct value `344.44921875`) and its denominator computation overflows `unsigned int` from r = 13. The closed form `C(2r,r)/2^r` is exact at every r tested (0–20), confirmed by `validation/test_neumann_adams.cpp` (24 checks, all passed) and no longer depends on any loop bound by r. |

No other issue in the register names this prompt's Fix 2 or Fix 3 directly; both were carried out
purely from the prompt text and `RECONCILIATION.md` §7.2/§7.3 (referenced by the prompt, not
independently re-read line-by-line for this log beyond the citations the prompt itself gives).

## 8. Notes for whoever comes next

- **The prompt's own worked table has a denominator typo.** Its "for cross-checking" section
  states `A(10)=46189/512` and `A(11)=88179/512`, but the *decimal* values quoted two lines above
  in the same prompt (`A(10) = ... = 180.425781250` and `A(11) = ... = 344.44921875`) are only
  consistent with denominator `256`, not `512` (`46189/256 = 180.42578125`, `46189/512 =
  90.212890625`; likewise for 11). This was caught by cross-checking against Python's
  `fractions.Fraction(comb(2*r, r), 2**r)` independently of both the prompt and this project's
  GiNaC computation, and all three (GiNaC here, Python `Fraction`, and the prompt's own quoted
  decimals) agree on `/256`. `validation/test_neumann_adams.cpp` pins the correct `/256` values
  and documents the discrepancy inline so a future reader who goes back to the prompt text is not
  confused by the mismatch.
- **The `assert()` inside `double_factorial` is compiled out in the actual shipped binary.** This
  project's Release build passes `-DNDEBUG` (confirmed from `build-validation/.../flags.make`),
  under which `<cassert>`'s `assert()` expands to nothing. The operative guard in production is
  therefore *only* the explicit `if(num == 0) throw ...` in `enumerate_contractions`, not the
  assert in `double_factorial`. The assert was kept anyway as documentation-in-code and as a
  safety net for anyone who builds a `Debug` configuration (or lints with assertions forced on),
  but a future reader should not believe it protects the release binary — it doesn't; the `throw`
  does. This is exactly the "defensible either way" case the prompt flagged, and this asymmetry
  (compiled-out in Release) is the reason to record the choice rather than assume the assert pulls
  its weight.
- **Fix 2 was not independently unit-tested.** `num == 0` cannot currently be reached (confirmed
  by the full run in §4 producing byte-identical output — if the guard's `if` were ever entered,
  the run would have thrown and `validation/run.sh` would have failed, which it did not), and
  building a realistic fixture for the internal templated `contractions` class (which needs a
  `service_locator&`, a `iv_group<N>`, and a `kext_group<N>`) purely to force `num == 0` through
  the constructor was judged disproportionate to a one-line guard whose sibling
  (`ERROR_ODD_CONTRACTIONS`, two lines above the constructor's own analogous check) is not
  separately unit-tested elsewhere in this codebase either. Verified by code inspection and by the
  full pipeline run, not by a dedicated test — recorded explicitly rather than left silent.
- **For prompt 06:** this prompt did not touch `lib/detail/Rayleigh_momenta.cpp` (the file with
  the commented-out throw prompt 06 is about) or anything in `lib/detail/contractions.h`'s
  `evaluate_Wick_contractions()` (prompt 04's file). No interaction expected between this prompt's
  changes and prompt 06's scope.
- **For prompt 07:** the wall-clock note in §5 (this project's actual `-O3` release flags, not
  the study's `-O1` figure) may be worth carrying into the handover document, since a reader who
  only sees "~2 s" from the study and does not read this log could be confused when re-measuring
  and finding a much smaller number.

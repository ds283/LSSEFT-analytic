# Findings: the zero-valued Rayleigh rules

**Prompt:** `prompts/pre-python-migration-fixes/06-rayleigh-zero-diagnosis.md`
**Date:** 2026-09-04
**Verdict: the study's proposed invariant does NOT hold.** No assertion or eager pruning was
implemented (step 3, items 1-2). Only the aliasing fix (step 3, item 3) was made. This is one of
the two outcomes the prompt explicitly anticipates and sanctions ("Stop. Do not attempt a fix.").

This document is written to stand alone: a reader does not need to re-run any instrumentation to
understand what was found or what remains open.

---

## 1. Background (30 seconds)

`lib/detail/Rayleigh_momenta.cpp:50-51` carries a commented-out throw:

```cpp
//            if(static_cast<bool>(value == 0))
//              throw exception(ERROR_RAYLEIGH_MOMENTUM_IS_ZERO, exception_code::Rayleigh_error);
```

A "Rayleigh momentum" is an auxiliary scalar label the code introduces whenever it needs a
denominator of the form `1/|Q|²` for some vector `Q` built out of the kernel's own momenta (e.g.
the SPT `alpha`/`beta` vertex functions, or `InverseLaplacian`). The label is a bare symbol; a
side table (`Rayleigh_list`, a `GiNaC::exmap`) separately records what physical momentum
expression that symbol denotes. `merge_Rayleigh_rules` (`Rayleigh_momenta.cpp:34`) is called every
time two kernels carrying such tables are combined (added or multiplied), and it re-evaluates each
inherited rule's value against the current relabelling substitution. The study found that this
re-evaluation produces `value == 0` 128 times in a full canonical run, proposed the invariant

> *A Rayleigh rule may have value zero only if its label does not occur in the momentum kernel `K`*

as a replacement for the (too strong, and never fired) commented-out throw, and asked this prompt
to check it.

## 2. Step 1 — where the zero-valued rules come from

**Count: exactly 128**, confirmed by instrumenting the `if(static_cast<bool>(value == 0))` test at
`Rayleigh_momenta.cpp:50` directly (temporary, removed before commit — see §6) and counting hits
over one full canonical run (`--no-auto-symmetrize --symmetrize-22 --counterterms`). This matches
the study's figure exactly; no correction needed.

### 2.1 Where in the pipeline

**All 128 events occur inside `Pk_one_loop::cross_product`** (`lib/Pk_one_loop.h:353-436`), split
evenly as 64 from the `merge_Rayleigh_lists(rm1, ...)` call and 64 from `merge_Rayleigh_lists(rm2,
...)` (`Pk_one_loop.h:399-400`). **Zero events were never created** during the earlier kernel
*construction* phase — i.e. never inside `fourier_kernel_impl::kernel::operator+=` or `operator*=`
(`lib/fourier_kernel.cpp:150-260`), which also call `merge_Rayleigh_rules` while building up
`delta`, `phi`, `G2`, `G3`, `Gamma3`, etc. in `main.cpp`. This was checked directly (a
call-site tag was set immediately before each of the four `merge_Rayleigh_rules`/
`merge_Rayleigh_lists` call sites in the codebase and read from inside the merge function); zero
hits were recorded at the two `fourier_kernel.cpp` sites, one hundred per cent at the two
`Pk_one_loop.h` sites.

This makes sense once the mechanism is seen: `Pk_one_loop::cross_product` is the point where two
already-fully-built higher-order kernels are combined *per Wick contraction*, using a
contraction-specific momentum relabelling (`subs_maps[0]`/`subs_maps[1]`, obtained from
`detail::contractions`). It is exactly this contraction-specific relabelling — not anything about
kernel construction — that collapses a rule's value to zero.

### 2.2 The originating vertex functions

Two of the three sites that mint new Rayleigh symbols contribute:

| Origin | Zero-event count | Share |
|---|---|---|
| `alpha()` (`SPT/one_loop_kernels.cpp:30-40`), the `Q_sym` label | 40 | 31 % |
| `InverseLaplacian()` (`lib/fourier_kernel.h:978-999`), the `label_sym` label | 88 | 69 % |
| `beta()` (`SPT/one_loop_kernels.cpp:43-59`), the `Q_sym`/`S_sym` labels | **0** | 0 % |

`beta()` mints two Rayleigh labels per call and neither ever degenerates to zero in this run. This
was not investigated further (out of scope: the prompt asks for the pattern, not an exhaustive
explanation of every non-occurrence).

Only 24 distinct symbol names are involved in the 128 events (the same handful of labels recur
across many different `(t1, t2, Wick contraction)` triples, since the underlying kernel is reused
across many contractions).

### 2.3 The pre-substitution value, and what collapses it

Every one of the 128 pre-substitution values (`v.second` at `Rayleigh_momenta.cpp:48`, i.e. the
value *before* `subs_rules` is applied) is a **sum of exactly two of the model's linear
initial-value momentum symbols** — patterns observed: `q2+q1`, `q1+q0`, `q0+q8`, and similar. In
every single case, the Wick-contraction substitution map (`subs_maps[i]`) that is then applied
assigns those two symbols to be exactly equal and opposite — e.g.

```
pre_sub=q2+q1  subs_rules={q2->-l0, q1->l0, q0->-k}      -> value = 0
pre_sub=q0+q8  subs_rules={q0->l109, q8->-l109, q63->-k} -> value = 0
```

This is **exactly the study's hypothesis** — "the same momentum appearing with both signs" —
though the mechanism is more general than the study's guess of `Galileon2`/`Galileon3`/`gradgrad`
specifically: those functions are built by *composing* `alpha`/`beta`/`InverseLaplacian` internally
(via `alpha_bar`, `gamma_bar`, and direct `InverseLaplacian` calls in `main.cpp`'s construction of
`delta`, `phi`, `Phi_delta`, `G2`, `G3`), so the finding is consistent with, but sharper than, the
study's guess: **the zero arises specifically when a Wick contraction self-contracts two of a
single higher-order kernel's own linear "legs" against each other through a loop propagator**,
forcing their momenta to be equal and opposite. This is a routine feature of one-loop SPT diagrams
(a `P13`-type self-loop on a third-order kernel), not something exotic. Consistent with this: every
one of the 92 violating events (see §3) carries a Wick string of the schematic form
`Pk(delta,delta,k)*Pk(delta,delta,l<n>)`, the signature of a `P13` contraction, and time functions
drawn from the third-order growth-factor basis (`DD`, `DJ`, `DF`, `DG`, `DE`, ... — the labels
`delta_3`'s construction in `main.cpp` uses).

## 3. Step 2 — the invariant

### 3.1 What was tested, and at what stage

The study's invariant is: *for a zero-valued rule, does its label occur in `K`?* This is exactly
the test `prune_Rayleigh_list` (`Rayleigh_momenta.cpp:167-187`) already performs for every rule
(zero or not), using `get_expr_symbols` (`utilities/GiNaC_utils.h:63`). The natural, and only
principled, place to evaluate it is therefore **the same point in the pipeline where
`prune_Rayleigh_list` itself runs**: inside `Pk_one_loop::cross_product`, immediately before the
call at `Pk_one_loop.h:424`, using the fully-assembled `K` for that specific
`(t1, t2, Wick contraction)` term.

This is deliberate, not a default: the label's own *value* is only ever computed inside
`merge_Rayleigh_rules`, which does not have access to any `K` at all (it operates purely on the
`exmap` substitution lists) — checking "occurs in `K`" there is not meaningful, because at that
point `K` for the eventual power-spectrum term does not yet exist in assembled form. The instrument
that produced the counts below did **not** attempt to check the invariant at kernel-construction
time (`fourier_kernel.cpp`'s `operator+=`/`operator*=`) for the stronger reason given in §2.1: no
zero-valued rule is ever created there in the first place, so there is nothing to check at that
earlier stage.

**Two checkpoints within `cross_product` were compared**, to address the prompt's explicit warning
that a label may enter or leave `K` as relabelling proceeds:

- **early**: immediately after `K = relabel_index_product(K1_remap, K2_remap, this->loc)`
  (`Pk_one_loop.h:407`), i.e. before `remove_Rayleigh_trivial` or `simplify_index` have touched `K`;
- **late**: immediately before `prune_Rayleigh_list` runs, i.e. after `K.subs(Rayleigh_triv)` and
  `simplify_index(K, dotp, Rayleigh_list, this->loc)`.

**The two checkpoints agree exactly**, event for event: 92 of 128 violate at *both* stages, 36 of
128 hold at *both* stages. `remove_Rayleigh_trivial` cannot affect this (it never removes a
zero-valued rule — that is exactly the defect the prompt records as already known). The Rayleigh
power-cancellation logic inside `simplify_index`/`simplify_mul`
(`utilities/GiNaC_utils.cpp:156-206`), which *can* algebraically cancel `1/label²` against a
matching power of the rule's own value elsewhere in the same product, cannot fire for a zero-valued
rule either: it works by pattern-matching `pow(indexed(value, idx), n)` against a factor actually
present in the expression, and `indexed(0, idx)` is not a pattern that ever matches a real
sub-expression, since GiNaC eliminates a literal `0` on sight. So there is, in fact, only one
meaningful checkpoint here — the invariant's truth value is fixed by the time `K` is assembled at
all, at least across the window this diagnosis was able to observe.

### 3.2 The refined test: denominator, not just presence

A crude "does the symbol appear anywhere in `K`" test does not distinguish a genuinely hazardous
`1/label²` occurrence from a harmless one where `label` only appears with positive power (in which
case substituting `label → 0` would just zero that whole sub-term, not divide by zero). Since every
Rayleigh label enters `K` **only** via the `1/Q.norm_square()`-type factor that `alpha`, `beta` and
`InverseLaplacian` multiply in (`SPT/one_loop_kernels.cpp:38`, `:56-58`;
`lib/fourier_kernel.h:995`), and nowhere else, the sharper test was also run: does the label occur
in `K.normal().denom()` — the denominator of `K` after being put over one common denominator and
having common factors with the numerator cancelled?

**Result: identical to the crude test.** All 92 "occurs in `K`" events occur specifically in the
normalised denominator; none are numerator-only artifacts. `.normal()` is GiNaC's own rational
simplification, so if a `1/label²` sub-term had genuinely cancelled against something else in the
sum making up `K`, `.normal()` should have removed `label` from the reduced denominator — it did
not, in any of the 92 cases.

### 3.3 Verdict

**The invariant is violated in 92 of 128 cases (71.9 %); it holds in 36 of 128 (28.1 %).** This is
tested at a single, well-defined, and — as far as this diagnosis could establish — the *only*
meaningful pipeline stage (§3.1), and the violations are confirmed to be genuine denominator
occurrences, not an artefact of the test (§3.2).

**This is squarely the "does not hold" branch the prompt anticipates.** Per its explicit
instruction, no assertion and no eager pruning were implemented (step 3, items 1-2 were not done).

### 3.4 The open question this hands to a physicist

92 of 128 zero-valued Rayleigh rules have their label present in a genuine `1/label²` factor of `K`
at the last point `K` is available for that term, and yet **the full canonical run completes
cleanly**: exactly the same 3 warnings as every other prompt in this campaign, and critically **no
`ERROR_NO_LOOPQ_IN_RAYLEIGH`** (`localizations/en/messages_en.h:107`, thrown by
`one_loop_reduced_integral::reduce` when a selected Rayleigh momentum's value has degree 0 in the
loop momentum — which a literal `0` trivially does). The prompt's own background material already
established this negative fact ("if a zero-valued Rayleigh momentum were ever selected... the
one-Rayleigh path would immediately throw... The run completes, so none is ever selected"); this
diagnosis confirms it is still true after the fixes in prompts 04-05, and adds the *positive* fact
that the label really is present in `K`'s denominator for most of these events, not merely
in `Rayleigh_list` as inert bookkeeping.

So there must be a mechanism, downstream of everything this diagnosis instrumented (i.e. inside
`one_loop_reduced_integral::reduce()` and the machinery that *selects* which Rayleigh momentum from
`Rayleigh_list` becomes "the" reduction variable `R` for a given `1/|R|^{2n}` factor), that
prevents these 92 surviving zero-valued labels from ever actually being selected and evaluated
numerically. Candidate explanations, **none of which were verified here** (this is exactly the line
the prompt draws between an implementation task and a physics one):

1. **A genuine IR cancellation.** The `alpha`/`beta` vertex functions are known in the SPT
   literature to carry individually-singular `1/k²`-type structures at small `k` that cancel
   between different contraction terms of the same order when properly summed — plausible here,
   since `K` as checked is the term for one *single* Wick contraction, not the sum over all
   contractions contributing to the same `(t1, t2)` kernel product. If the numerator's own
   structure vanishes to matching order at the same locus (a fact the crude/refined tests above
   cannot see, since `K.normal()` operates on this one term in isolation and does not know about
   the other terms it will eventually be summed against), the surviving factor could be an
   arithmetic artefact that becomes finite (or is not the leading, loop-momentum-carrying factor)
   only after further summation — but that summation happens well after the point checked here.
2. **The reduction machinery's own selection rule never picks these specific labels.** If
   `one_loop_reduced_integral::reduce()` always prefers some other, non-degenerate Rayleigh momentum
   present in the same `K` (there is often more than one surviving rule per term) as the variable
   it expands in, the zero-valued factor might sit inert in the expression, structurally present but
   never substituted or evaluated. This was not traced; `one_loop_reduced_integral.cpp`'s selection
   logic (`order_Rayleigh_set`, the machinery around `loop_integral.cpp:172` and `:241`) is a
   substantial, separate piece of code this diagnosis did not instrument.
3. **A degree-0 label is silently absorbed elsewhere**, e.g. if the surviving `1/label²` factor
   is itself multiplied by an *indexed* (not scalar) quantity that later cancels through
   `simplify_indexed`'s own separate logic, invisible to a plain-symbol occurrence test.

**What a port author needs to know:** on the current operator basis, the pipeline is empirically
safe (no crash, and — see §5 — functionally unchanged output, confirmed against the archived
baseline). But the mechanism that makes it safe for these 92 cases is not established by any code
comment, test, or this diagnosis. A Python/SymPy port that re-derives Rayleigh reduction from first
principles should not assume "label present in `K`, value zero" is impossible or automatically
harmless; it should either reproduce whatever selection/cancellation mechanism actually protects
correctness here (which requires reading `one_loop_reduced_integral::reduce()` in full), or
independently verify, symbolically, that every one of these 92 configurations reduces to a finite
result before trusting it as a differential-oracle match.

## 4. What *was* implemented: the aliasing fix (step 3, item 3)

Independent of the invariant's verdict, the prompt asks for the aliasing bug at
`Rayleigh_momenta.cpp:54-74` to be fixed regardless, since it is "one line and it removes a trap."

**The bug:** `merge_Rayleigh_rules` searches `dest` twice — once for an existing rule whose value
equals `value`, once for one whose value equals `-value`. For `value == 0`, both predicates are
`a.second == 0` (`-0 == 0`), so the *second* search silently re-tests exactly what the first
already tested. Because the first search already handles the case of a match via `continue`, the
second search only ever runs when the first found nothing (i.e. no zero-valued rule yet exists in
`dest`) — at which point it necessarily also finds nothing, since it is testing the identical
predicate. The two searches are meant to be independent (`value` vs. `-value`); for zero they
degenerate into the same test, which is a trap for anyone reading or extending this code, even
though the *current* behaviour is unaffected (the first search alone already produces the correct,
intended aliasing of every zero-valued rule onto the first zero-valued rule ever created in a given
`dest` map).

**The fix:** the `-value` search, and the block that acts on it, is now skipped entirely whenever
`value == 0`:

```cpp
if(!static_cast<bool>(value == 0))
  {
    u = std::find_if(dest.begin(), dest.end(),
                     [&](const auto& a) -> bool { return static_cast<bool>(a.second == -value); });
    if(u != dest.end())
      {
        mma_map[label_sym] = -u->first;
        continue;
      }
  }
```

This is provably behaviour-preserving (the skipped search could never have matched anything the
first search would not already have caught), and verified so: the emitted `autogenerated/` tree
is **byte-identical**, not merely functionally identical, before and after the fix (§5).

## 5. Verification

| Check | Expected | Observed | Verdict |
|---|---|---|---|
| Build | clean at `-std=c++17` | clean, zero project warnings | PASS |
| Kernel count | 101 | 101 | PASS |
| `compute_*` name count | 135 | 135 | PASS |
| Functional signatures vs. `baseline/pre-fix` | 101 of 101 matched | 101 of 101 matched | PASS |
| Dedup | 101 → 95, 6 pairs | 101 → 95, 6 pairs (identical pairing to prompts 04/05) | PASS |
| Counterterm map (canonicalised) | identical to baseline | byte-identical after header strip | PASS |
| Warning set | identical to baseline (3) | 3, identical text | PASS |
| Textual diff of `autogenerated/` vs. the prompt-05 tree (timestamp stripped) | expected empty | **empty across all 21 non-timestamp files** | PASS |
| New `ERROR_NO_LOOPQ_IN_RAYLEIGH` | none | none, in either the instrumented or final runs | PASS |
| Wall clock | ~43-47 s | 44.6 s user / 48.1 s wall (final run); 44-46 s user across all instrumented runs | PASS |

No new assertion was added (§3.3), so there is nothing to demonstrate "firing when violated" —
that verification item from the prompt applies only to the "invariant holds" branch.

Exact commands:

```bash
./validation/build.sh
./validation/run.sh "$PWD/validation/out/final"

python3 validation/compare_autogenerated.py --quiet validation/out/final/autogenerated \
  --signatures validation/baselines/pre-fix/signatures.json
# -> 101 of 101 matched, exit 0

python3 validation/canonical_form.py --dedup --expect 101:95:6 validation/out/final/autogenerated
# -> OK

python3 validation/canonical_form.py --counterterm-map validation/out/final.log > /tmp/final_ct_canon.txt
diff <(tail -n +17 validation/baselines/pre-fix/counterterm-map.canonical.txt) /tmp/final_ct_canon.txt
# -> no output

for f in validation/out/before-06/autogenerated/*.cpp; do
  bn=$(basename "$f"); [[ "$bn" == pipeline_id.cpp ]] && continue
  diff <(grep -v '^// Generated at' "$f") \
       <(grep -v '^// Generated at' "validation/out/final/autogenerated/$bn")
done
# -> no output at all: zero differences across all 21 files (byte-identical, not merely functional)
```

`validation/out/before-06` was a plain canonical run taken from the parent commit (`cc982d5`,
prompt 05 complete) before any change in this prompt, used purely as the "previous prompt's tree"
comparator required by the prompt's Verification item 2.

## 6. Instrumentation

Temporary instrumentation was added, gated behind a `LSSEFT_RAYLEIGH_INSTRUMENT` preprocessor
macro (never defined in the default build), to produce the counts and stage comparison above:

- a `lib/detail/rayleigh_instrument.h` header (all of it inside `#ifdef LSSEFT_RAYLEIGH_INSTRUMENT`)
  recording, per zero-value event: label, originating vertex tag, pre-substitution value,
  substitution rules applied, and (at the two `Pk_one_loop::cross_product` checkpoints) whether the
  label occurs in `K` and specifically in `K`'s normalised denominator;
- small `#ifdef`-guarded call sites in `lib/detail/Rayleigh_momenta.cpp`, `SPT/one_loop_kernels.cpp`,
  `lib/fourier_kernel.h`, `lib/fourier_kernel.cpp`, and `lib/Pk_one_loop.h`.

**All of this was removed before the final commit** (not merely gated off) — this repository has no
trace of `LSSEFT_RAYLEIGH_INSTRUMENT` or `rayleigh_instrument` (confirmed by
`grep -rn "LSSEFT_RAYLEIGH_INSTRUMENT\|rayleigh_instrument"` returning nothing outside
`build-validation/`), matching the precedent set by prompt 05's Legendre-shape instrumentation. The
counts in this document were captured from the instrumented run's `stderr` before removal; they are
not reproducible by re-reading the shipped source, only by re-adding equivalent instrumentation (the
mechanism is straightforward to reconstruct from §2-§3 above if ever needed again).

## 7. Summary for a reader in a hurry

- 128 zero-valued Rayleigh rules per canonical run, exactly matching the study. All 128 arise at a
  single call site (`Pk_one_loop::cross_product`'s two `merge_Rayleigh_lists` calls), never during
  kernel construction. Two originating vertex functions: `alpha` (40) and `InverseLaplacian` (88);
  `beta` contributes none.
- Mechanism: a Wick contraction that self-contracts two of a kernel's own linear legs against each
  other assigns them equal-and-opposite loop momentum, collapsing a pre-existing `A+B`-type
  Rayleigh value to zero. Confirms the study's "same momentum, both signs" hypothesis, generalised
  beyond the specific `Galileon2`/`Galileon3`/`gradgrad` functions it guessed.
- The proposed invariant ("zero ⇒ label absent from `K`") **fails in 92 of 128 cases (72 %)**,
  tested at the one meaningful pipeline stage, confirmed to be genuine denominator occurrences.
  **Verdict: does not hold.** No assertion, no eager pruning.
- The run is nonetheless empirically safe today (no crash, functionally unchanged output) via a
  mechanism this diagnosis did not — and could not, within scope — establish. That is now an
  explicit, documented open question (§3.4) for whoever ports or further modifies this reduction
  machinery.
- The aliasing fix (item 3c) was made regardless, is provably behaviour-preserving, and is verified
  byte-identical.

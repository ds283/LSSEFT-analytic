# Findings: the zero-valued Rayleigh rules

**Prompt:** `prompts/pre-python-migration-fixes/06-rayleigh-zero-diagnosis.md`
**Date:** 2026-09-04
**Verdict (revised 2026-09-05): the study's proposed invariant HOLDS, for all 128 cases.** The
original verdict of 2026-09-04 ("does NOT hold; 92 of 128 violate") was wrong: it applied a
syntactic test to a representation of `K` in which the vanishing of the relevant coefficient is not
yet manifest. The corrected reasoning is in §3 and the resolution, with a checkpoint table, is in
§8. On 2026-09-04 no assertion or eager pruning was implemented (step 3, items 1-2), following the
prompt's "Stop. Do not attempt a fix." branch; only the aliasing fix (step 3, item 3) was made. §8.4
records where an assertion can now safely go, and why the eager-pruning proposal must *not* be
implemented as originally worded.

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
expression that symbol denotes. The label appears in `K` only with negative even powers; numerators
are always written in the underlying momenta (`alpha`, `beta` and `InverseLaplacian` are the only
functions that mint labels, each via the three-argument `multiply_kernel`). The point of the device
is to keep a non-rotationally-invariant denominator symbolic until the numerator has been reduced,
which is what makes the Rayleigh plane-wave expansion possible later. `merge_Rayleigh_rules` (`Rayleigh_momenta.cpp:34`) is called every
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

**The physics of these events (added 2026-09-05).** The zero-valued rule is the code's
representation of the third-order kernel evaluated at `F3(L, -L, k)`. In that configuration the SPT
vertex `alpha(k12, k3)` with `k12 = s + t = 0` is formally `0/0`: its denominator `|s+t|²` vanishes,
but so does its numerator `(s+t).(s+t+q)`; likewise for every `InverseLaplacian` of a second-order
object (`Phi_2`, `phi_2`) whose total momentum is `s+t`, because `Galileon2`, `gradgrad` and
`Laplacian` all multiply in a numerator proportional to `s+t`. The whole term is therefore
identically zero, not singular. The label is exactly what keeps GiNaC from evaluating `pow(0, -2)`
and throwing `power::eval(): division by zero` (which is what an *unlabelled* `1/|s+t|²` would do
at this point; verified directly). A zero-valued rule is thus the Rayleigh bookkeeping doing its
job, and the commented-out throw is too strong for a good reason. The difference between the 36
"holding" and 92 "violating" events of §3 is only *how manifestly* the numerator vanishes: in the 36
cases an `indexed(0, i)` factor evaluates to zero on substitution and `prune_Rayleigh_list` removes
the rule; in the 92 cases the cancellation needs `(L0.i)^2 * (L0.j)^(-2) = 1`, which GiNaC's indexed
algebra does not perform (§8).

## 3. Step 2 — the invariant

### 3.1 What was tested, and at what stage

The study's invariant is: *for a zero-valued rule, does its label occur in `K`?* This is exactly
the test `prune_Rayleigh_list` (`Rayleigh_momenta.cpp:167-187`) already performs for every rule
(zero or not), using `get_expr_symbols` (`utilities/GiNaC_utils.h:63`). On 2026-09-04 it was
evaluated inside `Pk_one_loop::cross_product`, immediately before the call at `Pk_one_loop.h:424`,
using the fully-assembled `K` for that specific `(t1, t2, Wick contraction)` term, at two
checkpoints:

- **early**: immediately after `K = relabel_index_product(K1_remap, K2_remap, this->loc)`
  (`Pk_one_loop.h:407`), i.e. before `remove_Rayleigh_trivial` or `simplify_index` have touched `K`;
- **late**: immediately before `prune_Rayleigh_list` runs, i.e. after `K.subs(Rayleigh_triv)` and
  `simplify_index(K, dotp, Rayleigh_list, this->loc)`.

**The two checkpoints agree exactly**, event for event: 92 of 128 have the label in `K` at *both*
stages, 36 of 128 at neither. That measurement is correct. The error in the original write-up was
to call this "the only principled place" to test, and to read syntactic presence of the label as
algebraic dependence on it. Both `cross_product` checkpoints see `K` as a GiNaC *indexed*
expression, and GiNaC's indexed algebra is not a normal form: `simplify_indexed` does not cancel
`(L0.i)^2` against `(L0.j)^(-2)` when the two dummy indices differ (verified directly on the 92
offending sub-sums; it returns every one of them nonzero). So a term can be present in `K` with a
literally nonzero GiNaC coefficient and still be identically zero as a function of the momenta.

The stage at which the test is meaningful is the first point where `K` is in *scalar* form. That is
the top of the `one_loop_reduced_integral` constructor, where `dot_products_to_cos(K).expand()`
rewrites every `(L0.i)^2` as the scalar `L0*L0` and every contracted pair `a.i*b.i` as
`a*b*Cos(a,b)`. A third checkpoint placed there (2026-09-05, §8) finds **zero** of the 128 labels
surviving. `remove_Rayleigh_trivial` cannot affect any of this (it never removes a zero-valued
rule), and the Rayleigh power-cancellation logic inside `simplify_mul`
(`utilities/GiNaC_utils.cpp:156-206`) cannot fire for a zero-valued rule either, since it
pattern-matches `pow(indexed(value, idx), n)` and `indexed(0, idx)` evaluates to `0` on sight.
Neither observation bears on the verdict; the cancellation that matters is the `|L|²/|L|²` one.

### 3.2 The refined test: denominator, not just presence

A crude "does the symbol appear anywhere in `K`" test does not distinguish a genuinely hazardous
`1/label²` occurrence from a harmless one where `label` only appears with positive power (in which
case substituting `label → 0` would just zero that whole sub-term, not divide by zero). Since every
Rayleigh label enters `K` **only** via the `1/Q.norm_square()`-type factor that `alpha`, `beta` and
`InverseLaplacian` multiply in (`SPT/one_loop_kernels.cpp:38`, `:56-58`;
`lib/fourier_kernel.h:995`), and nowhere else, the sharper test was also run: does the label occur
in `K.normal().denom()` — the denominator of `K` after being put over one common denominator and
having common factors with the numerator cancelled?

**Result: identical to the crude test**, and for the same reason it is not informative. `.normal()`
is GiNaC's rational normal form over *atoms*, and it treats every `indexed` object as an opaque
atom: `(L0.i)^2` and `(L0.j)^(-2)` are different atoms to it, so the sub-terms
`X*(L0.i)^2*(L0.j)^(-2)*(S0.k)^(-2)` and `-X*(S0.k)^(-2)` do not cancel and `S0` stays in the
"reduced" denominator. The refined test therefore measured the same syntactic fact as the crude
one. What it was intended to establish (that the coefficient of `1/label²` is genuinely nonzero) is
false for all 92 cases (§8).

### 3.3 Verdict

**Original (2026-09-04): "violated in 92 of 128 cases (71.9 %)". Revised (2026-09-05): holds in
128 of 128.** The 92 "violations" are terms whose coefficient is identically zero but whose vanishing
requires the cancellation `(L0.i)^2 * (L0.j)^(-2) = 1`, which happens at the cosine conversion at
the top of `one_loop_reduced_integral`, downstream of the checkpoints used on 2026-09-04. The
`K.normal().denom()` test of §3.2 cannot see that cancellation and so did not confirm anything.

No assertion and no eager pruning were implemented on 2026-09-04; see §8.4 for what can now be done.

### 3.4 The mechanism (was: "the open question this hands to a physicist")

The 2026-09-04 text of this section recorded that the run completes with no
`ERROR_NO_LOOPQ_IN_RAYLEIGH` (`localizations/en/messages_en.h:107`, thrown by
`one_loop_reduced_integral::reduce` when a selected Rayleigh momentum's value has degree 0 in the
loop momentum) despite 92 labels being present in `K`, and offered three candidate explanations,
none verified. The mechanism was established on 2026-09-05 (§8) and none of the three candidates was
right:

1. *A genuine IR cancellation across Wick contractions* — no. Every one of the 92 terms is
   individually and identically zero; no summation over contractions or over `(t1, t2)` pairs is
   involved. (22 records are merged in `Pk_db::emplace` for unrelated reasons, and the labels are
   still present in the merged `K`.)
2. *The reduction's selection rule never picks these labels* — no. `one_loop_reduced_integral::reduce`
   selects by `term.has(sym)` over every rule in the list, so any label present in a term *is*
   selected. `order_Rayleigh_set` (`loop_integral.cpp`) is a hashing/ordering helper, not a
   selection rule. Had a zero-valued label reached `reduce()`, the run would have thrown.
3. *Absorbed by `simplify_indexed`'s own logic* — closest, but the operative step is not
   `simplify_indexed` (which demonstrably does *not* cancel these terms) but `dot_products_to_cos`,
   which converts indexed objects to scalars so that ordinary `expand()` cancels them.

The pipeline is therefore *exactly* safe, not merely empirically safe, and it is safe by
construction: labels are confined to denominators, numerators are written in the underlying
momenta, and the scalar conversion runs before any Rayleigh label is selected. These are design
decisions of the reduction, not coincidences (§8.3).

**What a port author needs to know** (replaces the 2026-09-04 text): a zero-valued Rayleigh rule
whose label is present in the raw indexed `K` is the normal signature of a `P13`-type
self-contraction and denotes a term that is identically zero. A port must (a) never substitute a
zero value into a label carrying a negative power, since that is a genuine `1/0` at the algebra
level, and (b) reduce each term to scalar form (or otherwise canonicalise `|L|²` factors) *before*
deciding whether it is nonzero or whether a label is "in use". Checked in that order, the invariant
holds and can be asserted (§8.4).

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

The 2026-09-05 resolution (§8) used three further temporary `std::cerr` probes: at the end of the
`loop_integral` constructor, in the merge branch of `Pk_db::emplace`, and at the top of the
`one_loop_reduced_integral` constructor both before and after `dot_products_to_cos`. They were
reverted with `git checkout` before anything was committed, and the binary was rebuilt from the
clean tree. The counts they produced are in §8.1 and the verbatim sub-terms in §8.2.

## 7. Summary for a reader in a hurry

- 128 zero-valued Rayleigh rules per canonical run, exactly matching the study. All 128 arise at a
  single call site (`Pk_one_loop::cross_product`'s two `merge_Rayleigh_lists` calls), never during
  kernel construction. Two originating vertex functions: `alpha` (40) and `InverseLaplacian` (88);
  `beta` contributes none.
- Mechanism: a Wick contraction that self-contracts two of a kernel's own linear legs against each
  other assigns them equal-and-opposite loop momentum, collapsing a pre-existing `A+B`-type
  Rayleigh value to zero. Confirms the study's "same momentum, both signs" hypothesis, generalised
  beyond the specific `Galileon2`/`Galileon3`/`gradgrad` functions it guessed.
- The proposed invariant ("zero ⇒ label multiplies nothing") **holds in 128 of 128 cases**. The
  2026-09-04 verdict "fails in 92 of 128" tested syntactic presence of the label in an indexed
  `K` at `cross_product`, where the cancellation `(L0.i)^2 (L0.j)^(-2) = 1` has not yet been
  performed; at the first scalar representation (after `dot_products_to_cos`) no label survives.
- The run is exactly safe, by construction: labels live only in denominators, numerators carry the
  underlying momenta and vanish identically at `F3(L, -L, k)`, and the scalar conversion precedes
  Rayleigh selection. The resolved mechanism and a checkpoint table are in §8.
- An assertion can now be added after the cosine conversion (§8.4). The eager-pruning proposal
  must not be implemented by substitution (§8.4).
- The aliasing fix (item 3c) was made regardless, is provably behaviour-preserving, and is verified
  byte-identical.

## 8. Resolution (2026-09-05)

### 8.1 Probes

Three temporary probes (removed afterwards, §6) recorded, for every rule with value `0` in the
canonicalised `Rayleigh_momenta` list of a `loop_integral`, whether its label occurs in `K`:

| Checkpoint | Records with a zero-valued label present in `K` |
|---|---|
| End of the `loop_integral` constructor (after `match_Wick_to_Rayleigh` and canonicalisation) | **92**, all with Wick product `Pk(delta,delta,k)*Pk(delta,delta,L0)` |
| After merging in `Pk_db::emplace` (`*kernel += *elt`) | 22 merge events; the label is still present in every merged `K` |
| Top of `one_loop_reduced_integral`, raw `K` | **70** (= 92 − 22) |
| Same point, after `dot_products_to_cos(K).expand()` | **0** |

The first row reproduces the 92 of §3 exactly. The last row is why `reduce()` never sees a
zero-valued label and never throws.

### 8.2 The surviving sub-terms

Every one of the 92 sub-sums carrying a zero-valued label has the shape
`X * (1 - (L0.i)^2 * (L0.j)^(-2))`. Two representative examples, verbatim from the probe output
(`S0`, `S1` are canonical Rayleigh labels, `L0` the canonical loop momentum, `i<n>` dummy indices):

```
-(L0.i126)^2*(L0.i207)^2*b1_1*(S0.i97)^(-2)*bGamma3*(L0.i92)^(-2) + (L0.i126)^2*b1_1*(S0.i97)^(-2)*bGamma3
-(L0.i54)^2*(S0.i53)^(-2)*b1_1*b1_3 + 1/2*(L0.i54)^2*(L0.i51)^(-2)*(L0.i50)^2*(S0.i53)^(-2)*b1_1*b1_3 + 1/2*(L0.i54)^2*(L0.i50)^2*(S0.i53)^(-2)*b1_1*b1_3*(L0.i49)^(-2)
```

`(L0.i207)^2 * (L0.i92)^(-2)` is `|L|²/|L|² = 1` written with two different dummy indices. It arises
from a `Laplacian` adjacent to an `InverseLaplacian` whose trivial rule (`Q -> L`) has been
substituted back by `remove_Rayleigh_trivial`; each operator mints its own dummy index. GiNaC's
`simplify_indexed` returns these sub-sums unchanged (checked for all 92), and `.normal()` treats
each indexed object as an atom (§3.2). `dot_products_to_cos` rewrites both factors as the scalar
`L0^2`, after which the terms are identical and `expand()` cancels them.

### 8.3 Why this is by design

The reduction in `one_loop_reduced_integral` relies on three properties that the rest of the code
enforces: Rayleigh labels appear only with negative even power (`simplify_mul` throws
`ERROR_RAYLEIGH_MOMENTA_POSITIVE_POWER` on a matched positive power, and `Laplacian` deliberately
does not mint a label); numerators are written in the underlying momenta by the `vector` class, so
they vanish identically whenever the labelled vector does; and the conversion to scalar form runs
before any term is classified by the Rayleigh labels it contains. Under these properties a
zero-valued rule can only ever multiply an identically-zero coefficient, which is the invariant the
study proposed. The 2026-09-04 diagnosis tested it before the third property had acted.

### 8.4 What can be done now

- **An assertion is safe at one place**: in the `one_loop_reduced_integral` constructor, after
  `K = dot_products_to_cos(K).expand()`, assert that no rule with value `0` has its label in `K` or
  in the Wick product. Placed anywhere earlier it fires spuriously (92 times).
- **The eager-pruning proposal must not be implemented as a substitution.** `remove_Rayleigh_trivial`
  works by returning a substitution map that is applied to `K`. Extending it to zero-valued rules
  would substitute `label -> 0` into `pow(indexed(label, i), -2)`, and GiNaC then throws
  `power::eval(): division by zero` (verified with a standalone GiNaC test). Zero-valued rules may be
  *dropped from the list* once the assertion above has passed, but never substituted.
- **For a Python/SymPy port**: reduce terms to scalar form (or canonicalise `|L|²` factors) before
  testing for zero or for label usage, and treat "zero-valued rule, label present in the raw indexed
  kernel" as the expected signature of a `P13` self-contraction rather than as a defect.

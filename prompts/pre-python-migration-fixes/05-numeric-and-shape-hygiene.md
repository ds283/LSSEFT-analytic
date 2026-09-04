# Prompt 05 — Numeric and expression-shape hygiene

You are working in `~/Documents/Code/LSSEFT-analytic`. **Read**
`prompts/pre-python-migration-fixes/README.md` and `RECONCILIATION.md` first.

## Objective

Three cheap fixes that convert *silently wrong* into *correct* or into *loudly stops*. This is
study §9 Phase −1 item 4, drawing on §7.2 and §7.3.

1. Replace the Neumann–Adams coefficient `A(r)` with its exact closed form, removing an unsigned
   overflow at r ≥ 11 and a 2×10⁹-iteration accidental loop at r = 0.
2. Guard `double_factorial(num - 1)` against `num == 0`.
3. Replace three hand-rolled destructurings of a GiNaC product, each of which silently mishandles a
   shape it does not recognise, with one uniform treatment that **raises** on anything unhandled.

None of these should change a single emitted number. All three would matter the moment the angular
order rises — which is exactly what a higher-derivative operator, a PNG operator or a higher μ power
does.

## Preconditions

- Prompts 01-03 complete. (Prompt 04 is independent of this one but should land first; see the
  README's ordering rationale.)
- Working tree clean. New branch.

---

## Fix 1 — `A(r)`: use the closed form

`lib/one_loop_reduced_integral.cpp:735-763`:

```cpp
static std::map< unsigned int, GiNaC::numeric > A_cache;

GiNaC::numeric A(unsigned int r)
  {
    if(A_cache.find(r) != A_cache.end()) return A_cache[r];

    unsigned int numerator = 1;
    unsigned int count = 2*r - 1;
    while(count > 1) { numerator *= count; count -= 2; }

    unsigned int denominator = 1;
    count = r;
    while(count > 1) { denominator *= count; count -= 1; }

    A_cache[r] = GiNaC::numeric{numerator} / GiNaC::numeric{denominator};
    return A_cache[r];
  }
```

This computes A(r) = (2r−1)!! / r! in `unsigned int`. Reproduced exactly during planning:

```
A(10) = 654729075/3628800    = 180.425781250   correct
A(11) = 864408687/39916800   =  21.655260116   correct value 344.4492...
A(12) = 2701530617/479001600 =   5.639919819
A(13) = 3113755985/1932053504 =  1.611630309
```

The numerator overflows 2³² at r = 11 and the denominator overflows at r = 13. There is no check,
and the failure is silent.

There is also an accident at r = 0: `unsigned count = 2*0 - 1` wraps to `4294967295`, the loop runs
≈2.1×10⁹ iterations multiplying every odd residue into a 32-bit accumulator, and returns **1** —
which is the correct answer, because the product of all odd residues mod 2³² is the identity.
Measured cost of that one call: **2.2 s at -O1** (the study quotes 0.15 s; either way it is a real,
observable one-off). It is called on every `partner_q.empty()` path
(`one_loop_reduced_integral.cpp:705-708` is the analogous site in the zero-Rayleigh version; the
Neumann–Adams caller is `NeumannAdamsSum` at `:768`).

**Instrumented finding from the study:** the largest argument actually reached is **r = 4**, with
`NeumannAdamsSum` seeing p ≤ 4 and q ≤ 4. So current results are unaffected — but the argument
range is bounded by 2p + q, and raising the angular order walks straight into the overflow.

### The fix

A(r) = (2r−1)!! / r! = C(2r, r) / 2^r, which is correct at r = 0 without special-casing
(C(0,0)/1 = 1) and needs no double-factorial loop:

```cpp
A_cache[r] = GiNaC::binomial(2*r, r) / GiNaC::pow(GiNaC::numeric{2}, r);
```

Use GiNaC's exact arbitrary-precision rationals — check the exact signature and return type of
`GiNaC::binomial` in the installed headers (`/opt/local/include/ginac/`) and make sure you get a
`numeric`, not an unevaluated `ex`. If the natural expression does not type-check cleanly, an
explicit `GiNaC::numeric` construction from CLN is fine; record what you did.

The study explicitly recommends patching this in the C++ even though the port will not have the
bug: *"a future operator basis reaching r ≥ 11 would otherwise make the oracle and the port
disagree with the oracle being the wrong one."*

**Note the expected side effect:** removing the r = 0 loop makes the run measurably faster (~2 s).
That is the *only* wall-clock change this prompt should produce. Record the before and after.

### Regression test

Add a self-contained check pinning A(0…20) against exact rationals. Suggested home:
`validation/test_neumann_adams.cpp`, built by `validation/build.sh` as a separate small target, or
a Python check that hard-codes the expected values. Either is fine — say which and why.

The first few, for cross-checking:

```
A(0)=1  A(1)=1  A(2)=3/2  A(3)=5/2  A(4)=35/8  A(5)=63/8  A(6)=231/16
A(7)=429/16  A(8)=6435/128  A(9)=12155/128  A(10)=46189/512
A(11)=88179/512   (= 344.44921875, the value the current code gets wrong)
```

Derive the rest from `C(2r,r)/2^r` rather than transcribing from here, and check r = 11 against
344.44921875 explicitly — that is the first value the old code gets wrong.

---

## Fix 2 — `double_factorial` underflow guard

`lib/detail/contractions.cpp:63-72` and its only caller at `:84`:

```cpp
size_t num_contractions = double_factorial(num-1);
```

`num` is guaranteed even by the check at `contractions.h:326-327`
(`if(num % 2 != 0) throw exception(ERROR_ODD_CONTRACTIONS, ...)`), but **zero is even**. With
`num == 0`, `num-1` is `SIZE_MAX` and `double_factorial` runs a loop from `SIZE_MAX` down by 2 —
effectively a hang.

`num == 0` means every cluster was empty. It cannot currently happen, but the guard is one line and
the failure mode is a hang rather than an error.

**Fix:** reject `num == 0` explicitly, before the `double_factorial` call, with a clear exception.
Add a message constant to `localizations/en/messages_en.h` alongside `ERROR_ODD_CONTRACTIONS`
(`:73`) — do not reuse `ERROR_ODD_CONTRACTIONS`, because zero is not odd and the message would lie.
Follow the existing naming and `constexpr auto` style in that file.

While you are there, consider also asserting inside `double_factorial` itself that its argument is
not `SIZE_MAX`. Defensible either way; record the choice.

**Out of scope:** the combinatorial cost of `enumerate_contractions` (enumerate all (N−1)!! pairings
then filter — 15 for six fields, 945 for ten, 135135 for fourteen). Pruning during generation is
study §7.1 Tier 2 and belongs with the spanning-tree work in the port. Do not do it here.

---

## Fix 3 — the three Legendre destructurings are one defect

Study §7.2. Three sites each dispatch on GiNaC's expression class to pull a product apart, and each
misses a case:

| Site | Shape it forgets | Consequence |
|---|---|---|
| `lib/one_loop_reduced_integral.h:388` — `integrate_Legendre` | a bare `symbol` or `function` at top level | the term is returned **unintegrated** — no 4π normalisation, and for a bare `LegP(n, q, k)` with n > 0 no zeroing by orthogonality |
| `lib/one_loop_reduced_integral.cpp:675` — zero-Rayleigh `apply_Legendre_orthogonality` | a top-level `power` containing a `LegP` | `LegP(n,q,k)**2` is swept into the prefactor `temp` and multiplied by 4π instead of being reduced by orthogonality |
| `lib/one_loop_reduced_integral.cpp:821-847` — one-Rayleigh `apply_Legendre_orthogonality` | it has **no shape check at all** and iterates `expr.op(i)` | fed a `numeric` (`nops() == 0`) the coefficient is silently **lost** (`temp` stays 1); fed a `power` (`nops() == 2`) `R**-2` becomes `R * (-2)` |

The study's instrumentation reports all three as **never taken** on the current operator basis. The
first requires a term of the expanded kernel with unit coefficient and no other factor, which the
current kernels never produce; the third is never reached because `integrate_Legendre` only
dispatches `mul`/`numeric`/`power`/`add` to it and `cosines_to_Legendre` produces linear
combinations of `LegP` rather than powers of them.

Note the asymmetry that makes this obviously a bug rather than a design: the zero-Rayleigh sibling
at `one_loop_reduced_integral.cpp:702` **does** throw `ERROR_BADLY_FORMED_LEGENDRE_SUM_TERM` on an
unrecognised shape, while the one-Rayleigh version at `:821` checks nothing.

### The fix

The study's prescription is to normalise every term to a **factor list** before inspecting it, so
that the same code path handles a `numeric`, a `symbol`, a `function`, a `power` and a `mul`
uniformly. In C++ over GiNaC, `utilities/GiNaC_utils.h:82` already provides
`GiNaC::exvector to_exvector(const GiNaC::ex& expr)` — check what it does with a non-`mul` and use
or extend it so that it behaves like SymPy's `Mul.make_args`, i.e. returns a one-element list for a
non-product.

Requirements on the result:

1. **All three sites use one shared helper** to enumerate factors. Three copies of the dispatch is
   the defect; do not ship a fourth.
2. The Legendre matcher must return a **multiplicity**, so that `LegP(n,q,k)**2` is seen as *two*
   Legendre factors rather than one opaque power. That is defect (d), and handling it in the matcher
   is where it belongs.
3. **Where the reduction genuinely does not know what to do, raise.** The existing throws
   (`ERROR_CANT_INTEGRATE_MORE_THAN_TWO_LEGP`, `ERROR_TOO_MANY_KEXT_IN_LEGENDRE_SUM`,
   `ERROR_FAILED_TO_REDUCE_TRIPLE_PRODUCT_LEGP`, `ERROR_BADLY_FORMED_LEGENDRE_SUM_TERM`,
   `ERROR_BADLY_FORMED_TOP_LEVEL_LEGENDRE_SUM`) must be preserved. Never fall through silently.
4. In particular, `one_loop_reduced_integral.h:388`'s
   `if(is_a<symbol>(term_ex) || is_a<function>(term_ex)) return term;` must not survive as a silent
   pass-through. Either route it through the uniform factor-list path (correct), or make it throw
   (acceptable, and what the study calls for: *"It should be an assertion, not a silent
   pass-through"*). Prefer the former if it is clearly correct; take the latter if you are not sure
   — but do not guess at the mathematics.

**Do not change the mathematics.** The orthogonality relations, the 4π normalisations, the
Neumann–Adams sum, the Fabrikant substitutions and the coefficient `4π/(2n+1)` all stay exactly as
they are. The only change is *how a product is taken apart* and *what happens when it has a shape
the code does not recognise*.

### How to know you have not broken it

Because none of the three branches is currently taken, a correct fix produces **no change at all**
in the output. That is a weak test on its own, so also:

- Add temporary instrumentation counting how often each shape class appears at each of the three
  sites over a full run, and record the distribution. This tells a future reader what the code
  actually sees, which is the fact the study had to build an instrumented binary to learn.
- Assert (temporarily, during development) that no term reaches the new "unhandled shape" throw
  during a full run. If one does, you have found something genuinely new — record it and report
  before proceeding.
- Optionally, unit-test the new factor-list helper directly on hand-built expressions:
  `LegP(2,q,k)`, `LegP(2,q,k)**2`, `3*LegP(2,q,k)`, `GiNaC::numeric(5)`, a bare symbol, and
  `R**-2`. This is the only way to exercise the previously-dead paths at all, and it is worth the
  twenty lines.

---

## Verification

1. `A(0…20)` regression test passes; `A(11) == 88179/512` exactly.
2. Wall clock ≈ 43 s **minus** roughly 2 s (the removed `A(0)` loop). Report both numbers. This is
   the only intended timing change.
3. **Functional equality with `baseline/pre-fix`** via `validation/compare_autogenerated.py`:
   identical signature multiset, identical 135 `compute_*` names, identical warning set.
4. Textual diff of `autogenerated/` against the previous prompt's tree — should be **empty**
   (post-prompt-03 the tree is deterministic). If it is not, explain every difference; this prompt
   should change nothing that is emitted.
5. Counterterm map unchanged after canonicalisation.
6. No new warnings; in particular still no `Unevaluated Fabrikant integral` and no
   `Detected failure of IR safety`.
7. Re-run the 2018 comparison — still a functional match.

## Deliverables

- `A(r)` closed form plus regression test.
- `double_factorial` / zero-field guard plus a new message constant.
- One shared factor-list helper, used by all three Legendre sites, raising on unhandled shapes.
- `prompts/pre-python-migration-fixes/logs/05-numeric-and-shape-hygiene.md`
- `IMPLEMENTATION_STATE.md` updated; issue I-08 closed.

## Log requirements

Use `logs/TEMPLATE.md`. Additionally:

- The A(r) before/after table, including the r = 11 and r = 13 overflow values, and the measured
  wall-clock change from removing the r = 0 loop.
- The measured shape distribution at each of the three Legendre sites over a full run — which
  classes actually appear, and confirmation that the previously-dead branches are still not taken.
- Where you put the shared factor-list helper and why there (`utilities/GiNaC_utils` vs. a new file
  vs. a private static in `one_loop_reduced_integral.cpp`) — an **implementation choice**.
- Your decision at `one_loop_reduced_integral.h:388`: uniform handling or throw, and the reasoning.
  If you chose to throw because you were not certain of the mathematics, **say that explicitly** —
  it is the honest answer and it tells the port author what still needs deciding.
- The new message constant's name and text.
- Whether you asserted inside `double_factorial` as well.

## Process

1. `IMPLEMENTATION_STATE.md`: prompt 05 → *In flight*.
2. Do the three fixes; they are independent, so verify after each rather than all at the end.
3. Log, update state, one commit:

```
Replace A(r) with its closed form and unify Legendre term destructuring

- A(r) = (2r-1)!!/r! was computed in unsigned int and overflows silently
  from r = 11 (A(11) = 21.655 against the correct 344.449); the denominator
  overflows from r = 13. Use the exact form C(2r,r)/2^r over GiNaC rationals,
  which is also correct at r = 0 without the accidental 2e9-iteration loop
  that the old code relied on returning 1. Instrumented runs reach only
  r = 4 today, so no emitted number changes.
- add a regression test pinning A(0..20) against exact rationals
- guard the num == 0 case before double_factorial(num-1), which otherwise
  underflows to double_factorial(SIZE_MAX); the existing check only rejects
  odd field counts and zero is even
- replace three separate hand-rolled destructurings of a GiNaC product with
  one shared factor-list helper that handles numeric, symbol, function,
  power and mul uniformly, tracks LegP multiplicity so LegP(n,q,k)**2 is
  seen as two factors, and raises on any shape it does not recognise
  instead of falling through silently

Verified functionally unchanged against baseline/pre-fix. Wall clock
<N> s, down from <M> s, entirely from removing the A(0) loop.

Refs: prompts/pre-python-migration-fixes/05-numeric-and-shape-hygiene.md

Co-Authored-By: Claude Opus 5 <noreply@anthropic.com>
```

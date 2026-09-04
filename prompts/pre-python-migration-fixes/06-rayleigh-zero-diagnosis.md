# Prompt 06 — Diagnose the zero-valued Rayleigh rules

You are working in `~/Documents/Code/LSSEFT-analytic`. **Read**
`prompts/pre-python-migration-fixes/README.md` and `RECONCILIATION.md` first.

## Objective

This is the one item in the campaign that needs an **answer** before it can need an edit. Study
§7.4 and §9 Phase −1 item 5.

`lib/detail/Rayleigh_momenta.cpp:50-51` carries a commented-out invariant:

```cpp
//            if(static_cast<bool>(value == 0))
//              throw exception(ERROR_RAYLEIGH_MOMENTUM_IS_ZERO, exception_code::Rayleigh_error);
```

The study re-enabled it as a warning and found the condition is reached **128 times** in a full run
— so it was commented out because it *fires*, not as dead defensive code. A Rayleigh label whose
value is zero denotes a 1/|0|² factor in the kernel.

The deliverable of this prompt is primarily a **findings document**. A code change follows only if
the findings support one.

## Preconditions

- Prompts 01-03 complete (04 and 05 preferably too). `validation/` harness works.
- Working tree clean. New branch.

## Background: what is known

**The rules are created but never used in a way that matters.** The code proves this itself: if a
zero-valued Rayleigh momentum were ever selected by `one_loop_reduced_integral::reduce`, the
one-Rayleigh path would immediately throw `ERROR_NO_LOOPQ_IN_RAYLEIGH`
(`localizations/en/messages_en.h:107`) — the zero expression has degree 0 in the loop momentum. The
run completes, so none is ever selected. They are created, carried, and then either pruned by
`prune_Rayleigh_list` (`Rayleigh_momenta.cpp:158-178`) or simply never referenced.

**The value is computed after relabelling.** `Rayleigh_momenta.cpp:48`:

```cpp
const GiNaC::ex& value = v.second.subs(subs_rules);
```

So the rule is created with a nonzero momentum sum and degenerates only when `subs_rules` collapses
it during kernel multiplication. The study's hypothesis: most likely a product of kernels in which
the same momentum appears with both signs — look at `Galileon2`/`Galileon3` and `gradgrad` in
`SPT/one_loop_kernels.{h,cpp}` and their use in `main.cpp`.

**`remove_Rayleigh_trivial` does not remove zero.** `Rayleigh_momenta.cpp:119-155` removes rules
whose right-hand side is a bare `symbol` or a `numeric * symbol`. A `numeric` zero is neither, so
zero-valued rules survive.

**There is an aliasing bug on top.** `Rayleigh_momenta.cpp:54-74` searches `dest` first for a rule
matching `value` and then for one matching `-value`:

```cpp
auto u = std::find_if(dest.begin(), dest.end(),
                      [&](const auto& a) -> bool { return static_cast<bool>(a.second == value); });
...
u = std::find_if(dest.begin(), dest.end(),
                 [&](const auto& a) -> bool { return static_cast<bool>(a.second == -value); });
```

For `value == 0` both tests match the **same** rule, so every zero-valued label is aliased onto the
first zero-valued rule ever created. Harmless while unused; not harmless if the invariant in step 2
below turns out to be false.

## The three steps, in order

### Step 1 — find out where they come from

Instrument rule *creation*. At each site where a Rayleigh rule is created or merged, record:

- the label symbol;
- the momentum sum **before** `subs(subs_rules)`;
- the substitution rules applied;
- the resulting value;
- enough context to identify the kernel: which Fourier kernel product, which vertex/operator, which
  contraction group. Look at `merge_Rayleigh_lists`' callers — start from
  `lib/detail/relabel_product.cpp` and `lib/fourier_kernel.cpp` — to see what context is available
  at the call site.

Run the canonical configuration and tabulate. Answer, concretely:

- How many zero-valued rules are created? (The study says 128; **verify**, do not assume.)
- How many distinct originating kernels/operators produce them?
- What is the pre-substitution momentum sum in each case, and which substitution collapses it?
- Does the pattern match the study's guess (same momentum appearing with both signs, from
  `Galileon2`/`Galileon3`/`gradgrad`), or is it something else?

Write this up. It is the substance of the prompt.

### Step 2 — establish the invariant that actually holds

The study proposes:

> *A Rayleigh rule may have value zero only if its label does not occur in the momentum kernel.*

i.e. the 1/|s|² factor is multiplied by something that has already vanished. This is a much sharper
statement than the commented-out throw, and it is checkable directly: for each zero-valued rule,
test whether its label symbol occurs in the kernel `K` at the point the rule exists.
`get_expr_symbols` in `utilities/GiNaC_utils.h:63` gives you the symbol set of an expression, and
`prune_Rayleigh_list` (`Rayleigh_momenta.cpp:158-178`) already does exactly this kind of test.

Report: does the invariant hold for all 128 (or however many) cases, or are there exceptions?

**If it holds** — proceed to step 3.

**If it does not hold** — there is a genuine 1/0 in the algebra. **Stop.** Do not attempt a fix.
Document precisely which rules violate it, what kernel they came from, and what the resulting
expression looks like. Mark the prompt *Blocked*, raise the issue, and report to the user: this
needs a physics answer, not an implementation one. The study says the same thing.

Be careful about the *timing* of the check. A rule's label may enter or leave the kernel as
relabelling proceeds, so state clearly at which point in the pipeline you evaluated the invariant,
and whether it holds at every such point or only at some. If it holds only at one specific stage,
that is the invariant, and it is a weaker statement — say so rather than rounding it up.

### Step 3 — assert it, and prune eagerly

Only if step 2 succeeded:

1. **Assert the invariant** where it holds — as a real check with a clear message, not a comment.
   Add a message constant to `localizations/en/messages_en.h` next to
   `ERROR_RAYLEIGH_MOMENTUM_IS_ZERO` (`:67`) if the existing text does not fit; the existing one
   says "Internal error: Rayleigh momentum is zero", which is the wrong statement for the invariant
   you will actually be asserting.

   **Do not re-enable the commented-out throw as written.** It would abort a working run. That is
   the whole point of this prompt.

2. **Prune zero-valued rules eagerly** in `remove_Rayleigh_trivial` (`Rayleigh_momenta.cpp:119`),
   which today removes only bare-symbol and `numeric * symbol` right-hand sides. Note that
   `remove_Rayleigh_trivial` returns a `trivmap` of removed rules for substitution back into the
   kernel — think about whether a zero-valued rule belongs in that map (substituting `s → 0` into a
   kernel that does not contain `s` is a no-op, but if it *does* contain `s` you have a division by
   zero, which is precisely what the invariant is supposed to exclude). Say what you decided.

3. **Fix the aliasing** at `Rayleigh_momenta.cpp:54-74`: guard the `-value` search so that a
   zero value does not match the same rule twice. Even if it is currently harmless, it is one line
   and it removes a trap.

## Explicitly out of scope

- Changing what the Rayleigh machinery *does* with non-zero rules.
- `canonicalize_Rayleigh_labels`' `GiNaC::exmap` ordering — that is prompt 03's territory.
- Any Tier 2/3 work on multi-external-momentum Rayleigh reduction.

## Verification

1. **Functional equality with `baseline/pre-fix`** via `validation/compare_autogenerated.py`.
   Pruning rules that are provably unused must not change any emitted number. If it does, the
   invariant in step 2 is not what you thought — stop and re-open step 2.
2. Textual diff of `autogenerated/` against the previous prompt's tree — should be empty.
3. Counterterm map unchanged after canonicalisation.
4. Warning set unchanged; in particular no new `ERROR_NO_LOOPQ_IN_RAYLEIGH`.
5. The new assertion does **not** fire on a full run of the canonical configuration.
6. The new assertion **does** fire if you deliberately violate it (construct a small test case, or
   temporarily negate the condition). An assertion that has never been seen to fire is not known to
   work.
7. Wall clock ≈ unchanged.

## Deliverables

- `validation/RAYLEIGH-ZERO-FINDINGS.md` — the step 1 and step 2 write-up. This is the primary
  deliverable and it must stand alone: counts, origins, the invariant tested, the verdict, and what
  a port author needs to know.
- If step 2 succeeded: the assertion, the eager pruning, the aliasing fix.
- If step 2 failed: no code change beyond the aliasing fix; the findings document explains what
  needs a human decision.
- Instrumentation removed or gated off by default.
- `prompts/pre-python-migration-fixes/logs/06-rayleigh-zero-diagnosis.md`
- `IMPLEMENTATION_STATE.md` updated; issue I-03 closed or replaced with a sharper statement.

## Log requirements

Use `logs/TEMPLATE.md`. Additionally:

- The actual count of zero-valued rules, next to the study's 128, with a comment if they differ.
- The originating kernels/operators, concretely named.
- The exact invariant you tested, the stage at which you tested it, and the verdict.
- What you decided about `trivmap` and zero-valued rules — an **implementation choice** with
  reasoning.
- If step 2 failed: everything a physicist would need to adjudicate it, without re-running your
  instrumentation.
- Whether the assertion was demonstrated to fire when violated, and how.

## Process

1. `IMPLEMENTATION_STATE.md`: prompt 06 → *In flight*.
2. Instrument, measure, write `RAYLEIGH-ZERO-FINDINGS.md`.
3. Decide, per step 2's verdict.
4. Implement (or not), verify, log.
5. `IMPLEMENTATION_STATE.md`: prompt 06 → *Complete* (or *Blocked*) with SHA; update issue I-03.
6. One commit. If the verdict was "invariant holds":

```
Establish and assert the invariant for zero-valued Rayleigh rules

The throw at Rayleigh_momenta.cpp:50 was commented out because it fires:
<N> Rayleigh rules per run degenerate to zero after relabelling. They are
never selected by one_loop_reduced_integral::reduce (which would throw
ERROR_NO_LOOPQ_IN_RAYLEIGH), so the run completes and the results are
correct, but nothing said why.

- instrumented rule creation to identify the origin: <what you found>
- established that <the invariant as you actually verified it>, and assert
  it rather than the stronger, false statement that was commented out
- remove_Rayleigh_trivial now prunes zero-valued rules eagerly; previously
  it removed only bare-symbol and numeric*symbol right-hand sides, so zero
  survived
- fix the aliasing in merge_Rayleigh_rules, where a zero value matched the
  same existing rule under both the 'value' and '-value' searches

See validation/RAYLEIGH-ZERO-FINDINGS.md.

Verified functionally unchanged against baseline/pre-fix.

Refs: prompts/pre-python-migration-fixes/06-rayleigh-zero-diagnosis.md

Co-Authored-By: Claude Opus 5 <noreply@anthropic.com>
```

If the verdict was "invariant does not hold", commit the findings document and the aliasing fix
only, with a subject like `Document zero-valued Rayleigh rules; defer the invariant`, and make the
body say plainly what is unresolved.

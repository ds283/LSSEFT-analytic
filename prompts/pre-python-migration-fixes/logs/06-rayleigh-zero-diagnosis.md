# Log 06 — Rayleigh-zero diagnosis

**Prompt:** `prompts/pre-python-migration-fixes/06-rayleigh-zero-diagnosis.md`
**Executed:** 2026-09-04
**Branch:** `pre-python-migration-fixes/06-rayleigh-zero-diagnosis`
**Commit:** `c88776f` — `Document zero-valued Rayleigh rules; defer the invariant`
**Parent commit:** `cc982d5` (prompt 05 complete)
**Status:** Complete (as a diagnosis) / **Blocked** (as a fix) — see verdict below

---

## 1. What this prompt was for

`lib/detail/Rayleigh_momenta.cpp:50-51` carries a commented-out throw that the study found fires
128 times per canonical run. This prompt's job was to establish *why*, test the study's proposed
replacement invariant ("a zero-valued Rayleigh rule's label never occurs in the momentum kernel
`K`"), and only implement a code fix if that invariant actually holds. If it does not, the prompt
explicitly directs stopping and documenting rather than forcing a fix.

**Verdict: the invariant does not hold** (92 of 128 cases violate it). Per the prompt's own
instructions for this outcome, no assertion or eager pruning was implemented. Only the aliasing fix
(step 3, item 3, which the prompt asks for regardless of the invariant's verdict) was made.

## 2. What was changed

| File | Change | Notes |
|---|---|---|
| `lib/detail/Rayleigh_momenta.cpp` | `merge_Rayleigh_rules`: guarded the second (`-value`) existing-rule search so it is skipped entirely when `value == 0`, instead of silently re-testing the identical predicate the first (`value`) search already ran | The aliasing fix, step 3 item 3(c) of the prompt |

New files:

| File | Purpose |
|---|---|
| `validation/RAYLEIGH-ZERO-FINDINGS.md` | The primary deliverable: full step 1/step 2 write-up, standalone-readable |

Deleted files: none. (Temporary diagnostic instrumentation — `lib/detail/rayleigh_instrument.h`
plus small `#ifdef`-guarded call sites in four other files — was added, used to produce the
findings, and then fully removed before this commit; see §5.)

## 3. Divergences from the prompt

### 3.1 Structurally required

**D-1 — step 3 items 1-2 (assertion, eager pruning) were not implemented.**
**Prompt asked:** implement the assertion and eager pruning *only if* step 2's invariant holds;
otherwise stop, document, and mark the prompt Blocked.
**Shipped:** the invariant does not hold (§ findings doc §3.3: 92 of 128 zero-valued rule
instances, 71.9 %, have their label present in `K`'s normalised denominator at the one meaningful
pipeline checkpoint). Per the prompt's own explicit branch for this outcome, no assertion and no
eager pruning were added.
**Obstacle:** not a technical obstacle — a measured fact. The prompt itself frames this as an
expected, sanctioned possible outcome ("this is an acceptable, expected possible outcome... not a
failure").
**Why this is minimal:** the prompt is unambiguous that forcing a fix past a failed invariant check
would be worse than not fixing it (it would either assert something false, silently discarding
correct-but-hard-to-classify terms via eager pruning, or both). See `validation/
RAYLEIGH-ZERO-FINDINGS.md` §3.4 for what remains open and why it needs a physicist, not an
implementation choice.

### 3.2 Implementation choices

> **D-2 — where to check the invariant, given `merge_Rayleigh_rules` has no access to `K`**
> **Prompt asked:** "test whether its label symbol occurs in the kernel `K` at the point the rule
> exists... Be careful about the timing of the check... state clearly at which point in the
> pipeline you evaluated the invariant."
> **Shipped:** checked at two points inside `Pk_one_loop::cross_product` (`lib/Pk_one_loop.h`):
> immediately after `K` is assembled (`relabel_index_product`, `:407`) and immediately before
> `prune_Rayleigh_list` runs (`:424`) — i.e. the exact stage `prune_Rayleigh_list` itself already
> uses for its own, structurally identical, membership test.
> **Options considered:** (a) check inside `merge_Rayleigh_rules` itself, where the label's `value`
> is actually computed (`Rayleigh_momenta.cpp:48-50`) — rejected, no `K` is available there; the
> function only ever sees `exmap` substitution lists, never the kernel expression they will
> eventually be substituted into. (b) Check at kernel-construction time
> (`fourier_kernel.cpp::operator+=`/`operator*=`), where `this->K` *is* locally available —
> investigated and found moot: instrumentation confirmed zero-valued rules are never created at
> those call sites at all (all 128 arise later, inside `Pk_one_loop::cross_product`; see findings
> doc §2.1), so there is nothing to check there. (c) the shipped choice, at the two points bracketing
> the only place `K` is both final-for-this-term and co-located with `Rayleigh_list`.
> **Criterion used:** the prompt's own hint ("`prune_Rayleigh_list` already does exactly this kind
> of test") points directly at this location; using its own checkpoint means the invariant is tested
> under exactly the same conditions the codebase's own pruning logic relies on, not an
> arbitrarily-chosen earlier or later point.
> **Trade-off a later reader might weigh differently:** the two checkpoints tested are close
> together (within the same function, a few lines apart) and turned out to agree exactly (92/36
> at both). A reader might want the invariant tested much further downstream, inside
> `one_loop_reduced_integral::reduce()`'s own Rayleigh-momentum-selection logic, to see whether a
> violating label is ever actually *selected* for numerical evaluation (as opposed to merely present
> syntactically in `K`). That was explicitly out of reach here — the prompt's own hint anchors the
> check to `prune_Rayleigh_list`'s existing methodology, and tracing the full selection logic in
> `one_loop_reduced_integral.cpp` is a substantially larger undertaking flagged in the findings doc
> (§3.4) as the open question for a physicist.

> **D-3 — the invariant test was sharpened beyond "occurs anywhere in `K`" to "occurs in `K`'s
> normalised denominator"**
> **Prompt asked:** test whether the label "occurs in the kernel `K`", using `get_expr_symbols` the
> way `prune_Rayleigh_list` does.
> **Shipped:** both the literal test (`get_expr_symbols(K)` membership, matching
> `prune_Rayleigh_list` exactly) and a sharper one (`get_expr_symbols(K.normal().denom())`
> membership) were run and compared.
> **Options considered:** (a) the literal test alone, as asked; (b) the literal test plus the
> denominator-specific refinement (shipped).
> **Criterion used:** a bare "occurs anywhere" test cannot distinguish a genuine `1/label²` hazard
> from a harmless positive-power occurrence (which would just zero that sub-term, not divide by
> zero) — and every Rayleigh label is known to enter `K` *only* via a `1/Q.norm_square()`-type
> factor at its minting site (`SPT/one_loop_kernels.cpp`, `lib/fourier_kernel.h`), so distinguishing
> numerator from denominator is directly meaningful here, not a generic embellishment. Running both
> costs nothing extra (the refinement is only computed when the literal test already found a hit)
> and materially strengthens the finding: all 92 violations under the literal test are confirmed to
> be denominator occurrences (0 numerator-only artifacts), ruling out the most obvious way the
> literal test could have been misleading.
> **Trade-off a later reader might weigh differently:** the prompt only asked for the literal test,
> so a reader strictly checking "did the log do what was asked" will find an addition beyond the
> letter of the instruction. It was judged in scope because it directly serves the instruction's own
> purpose (establishing whether the invariant, stated in terms of a "1/|0|² factor in the kernel",
> actually holds) rather than expanding it.

### 3.3 Unintended drift

None beyond incidental whitespace. `git diff` shows the change confined to
`lib/detail/Rayleigh_momenta.cpp`'s `merge_Rayleigh_rules` (the aliasing fix; three lines of
trailing-whitespace churn from editing around it, not a formatting sweep) plus the two required new
files and the status-board update. The temporary instrumentation touched four additional files
(`SPT/one_loop_kernels.cpp`, `lib/fourier_kernel.h`, `lib/fourier_kernel.cpp`, `lib/Pk_one_loop.h`)
during diagnosis; all four were fully reverted to their prompt-05 state (`git diff` against `cc982d5`
is empty for all four) once the counts were captured. Confirmed by `git diff --stat` showing only
the two files above.

## 4. Verification

All commands were run against `validation/build.sh`'s default `-DCMAKE_BUILD_TYPE=Release` build
(`-O3 -DNDEBUG`), rebuilt from a clean `build-validation/` directory for the final numbers below
(Apple clang 21.0.0 arm64, GiNaC 1.8.10 + CLN 1.3.7 from MacPorts, CMake 3.31.11, macOS 26.5.2,
Apple M1 Pro).

| Check | Expected | Observed | Verdict |
|---|---|---|---|
| Build | clean at `-std=c++17` | clean, zero project warnings | PASS |
| Kernel count | 101 | 101 | PASS |
| `compute_*` name set | identical to baseline (135 names) | 135 | PASS |
| Integrand signature multiset vs. `baseline/pre-fix` | 101 of 101 matched | 101 of 101 matched | PASS |
| Dedup | 101 → 95, 6 pairs | 101 → 95, 6 pairs, identical pairing to prompts 04/05 | PASS |
| Counterterm map (canonicalised) | identical to baseline | byte-identical after header strip | PASS |
| Warning set | identical to baseline (3) | 3, identical text; **no new `ERROR_NO_LOOPQ_IN_RAYLEIGH`** | PASS |
| Textual diff of `autogenerated/` vs. the prompt-05 tree (timestamp stripped) | expected empty | **empty across all 21 non-timestamp files** — byte-identical, not merely functionally identical | PASS |
| Wall clock | ~43-47 s | 44.6 s user / 48.1 s wall | PASS |

New-assertion firing demonstration: **not applicable**. No assertion was added (§3.1, D-1), since
the invariant it would assert does not hold.

Exact commands are recorded in `validation/RAYLEIGH-ZERO-FINDINGS.md` §5, and are not repeated here
to avoid the two documents drifting out of sync.

## 5. Behaviour that intentionally changed

**Nothing in the emitted `autogenerated/` tree.** The aliasing fix is provably behaviour-preserving
(the code path it removes could never have matched anything the preceding, unmodified search would
not already have caught — see `RAYLEIGH-ZERO-FINDINGS.md` §4), and this is verified, not merely
argued: the emitted tree is byte-identical (timestamp excepted) before and after the fix, across
all 21 non-timestamp files.

**Instrumentation, added and then fully removed.** During diagnosis, a `LSSEFT_RAYLEIGH_INSTRUMENT`
preprocessor macro (never defined by the default build) gated a temporary header
(`lib/detail/rayleigh_instrument.h`) and small call sites in
`lib/detail/Rayleigh_momenta.cpp`, `SPT/one_loop_kernels.cpp`, `lib/fourier_kernel.h`,
`lib/fourier_kernel.cpp`, and `lib/Pk_one_loop.h`, recording every `value == 0` event at rule
creation (label, originating vertex tag, pre-substitution value, substitution rules applied) and,
at two points inside `Pk_one_loop::cross_product`, whether the label occurred in `K` and
specifically in `K`'s normalised denominator. This was built with
`-DLSSEFT_RAYLEIGH_INSTRUMENT`, run three times over the canonical configuration to gather and then
cross-check the counts, and then **entirely removed** (not merely gated off) before this commit —
matching the precedent set by prompt 05's Legendre-shape instrumentation. Confirmed by
`grep -rn "LSSEFT_RAYLEIGH_INSTRUMENT\|rayleigh_instrument"` returning no matches outside
`build-validation/` (the build directory, itself gitignored).

## 6. Issues opened, closed or updated

| ID | Action | Detail |
|---|---|---|
| I-03 | **Replaced with a sharper, evidence-backed statement** (see `IMPLEMENTATION_STATE.md` §3) | Was: "128 zero-valued Rayleigh rules are created per run (unverified here)... Needs a physics answer if the proposed invariant fails." Now: the count is confirmed exactly (128), the originating mechanism and vertex functions are identified, and the invariant is confirmed to fail (92/128, 71.9 %) at the one meaningful pipeline stage — the open item is now precisely *why the run is nonetheless safe*, not merely "is the invariant true". See `validation/RAYLEIGH-ZERO-FINDINGS.md` §3.4 for the three candidate explanations, none of which were verified here, and what a port author needs to check before trusting these 92 configurations as a differential-oracle match. |

## 7. Notes for whoever comes next

- **The actual count matches the study exactly: 128, not "approximately" or "differently".** No
  discrepancy to explain, unlike some of the study's other unverified figures in this campaign.
- **All 128 events arise at a single call site** (`Pk_one_loop::cross_product`'s two
  `merge_Rayleigh_lists` calls), never during the earlier kernel-construction phase
  (`fourier_kernel.cpp`'s `operator+=`/`operator*=`, which also call the same underlying
  `merge_Rayleigh_rules`). This was not obvious from reading the code alone — it required
  instrumenting all four call sites and comparing — and materially simplified the "at what stage"
  question the prompt raises, since there was no earlier occurrence to compare against.
- **The mechanism is a routine one-loop self-contraction, not something exotic.** Every
  pre-substitution value is a sum of exactly two of the model's linear initial-value momentum
  symbols, and every violating case has a Wick contraction that pins those two symbols to be equal
  and opposite (a `P13`-type self-loop on a third-order kernel). This generalises, rather than
  narrowly confirms, the study's `Galileon2`/`Galileon3`/`gradgrad` guess: those functions are built
  by composing `alpha`/`beta`/`InverseLaplacian`, so the same mechanism reaches them, but is not
  specific to them (`beta`, in particular, contributes zero events in this run despite minting two
  Rayleigh labels per call — not investigated further; noted as an open, low-priority curiosity).
- **The open physics question (findings doc §3.4) is squarely a `one_loop_reduced_integral::reduce()`
  question**, specifically its logic for selecting which surviving Rayleigh momentum becomes "the"
  reduction variable for a given `1/|R|^{2n}` factor (`loop_integral.cpp`, around `order_Rayleigh_set`
  and `:172`/`:241`). That file was not instrumented or traced in this prompt; doing so is the
  natural next step for whoever picks this up, whether that is a future prompt in this campaign or
  the Python port itself.
- **For prompt 07:** carry the open question in `RAYLEIGH-ZERO-FINDINGS.md` §3.4 into the handover
  document verbatim or by close paraphrase — it is exactly the kind of "known-safe-but-not-understood"
  fact a differential-oracle port needs flagged explicitly, not rediscovered by a future failure.
- **Dead end, recorded so it is not retried:** checking the invariant inside `merge_Rayleigh_rules`
  itself (at the point `value` is computed, `Rayleigh_momenta.cpp:48-50`) is not possible without
  threading a `K` reference into a function whose entire contract is about `exmap` substitution
  lists, not kernel expressions — and even if threaded through, kernel construction was confirmed to
  never produce a zero-valued rule in the first place (§2.1 of the findings doc), so there would be
  nothing to check there regardless.

---

## Addendum (2026-09-05)

The open question above was resolved the next day, outside the campaign, and the verdict of this
prompt is reversed: **the proposed invariant holds for all 128 zero-valued rules.** The 92
"violations" are terms that are identically zero but whose vanishing requires
`(L0.i)^2 * (L0.j)^(-2) = 1`, which GiNaC's indexed algebra and `.normal()` do not perform; the
cancellation happens at `dot_products_to_cos(K).expand()`, the first statement of the
`one_loop_reduced_integral` constructor, before `reduce()` selects any Rayleigh label. The
"selection logic" this log pointed at is not involved (`reduce()` selects by `has()`, and would have
thrown had a zero-valued label reached it). See `validation/RAYLEIGH-ZERO-FINDINGS.md` §3 (corrected)
and §8 (resolution, with the checkpoint table 92 → 70 → 0), and `IMPLEMENTATION_STATE.md` I-03
(closed). The dead-end note above stands. **For prompt 07:** carry §8 of the findings document into
the handover, not the superseded §3.4 wording quoted here.

### Step 3, closed 2026-09-05

With the verdict reversed, the prompt's step 3 was revisited:

- **Item 1, assert the invariant — done.** The check lives in the `one_loop_reduced_integral`
  constructor, immediately after `K = dot_products_to_cos(K).expand()`: for every rule with value
  `0`, neither `K` nor the Wick product may contain its label, else
  `ERROR_RAYLEIGH_ZERO_LABEL_SURVIVES` (new constant in `localizations/en/messages_en.h`, next to
  `ERROR_RAYLEIGH_MOMENTUM_IS_ZERO`, whose text does not fit) is thrown. This is the *only* place the
  invariant holds: the same check placed before the cosine conversion aborts the run on the first
  `P13` record (demonstrated with a temporary build; the run terminated with the new message), so
  "fires when violated" is established. Verification of the shipped build: emitted tree
  byte-identical to the `5e2b208` tree (21/21 non-timestamp files), 101/101 signatures vs
  `baseline/pre-fix`, dedup 101 → 95 / 6 pairs, counterterm map and warning set identical.
- **Item 2, eager pruning in `remove_Rayleigh_trivial` — deliberately not done**, and the prompt's
  own caution is the reason: that function prunes *by substitution*, and substituting `label -> 0`
  into a `pow(indexed(label, i), -2)` factor makes GiNaC throw `power::eval(): division by zero`
  (verified with a standalone GiNaC test). At the point `remove_Rayleigh_trivial` runs the label
  *is* still in `K` (92 of 128 cases), so eager pruning there would abort a correct run. Zero-valued
  rules are harmless in the list: `reduce()` selects by `has()` and never sees them once the
  assertion above has passed. Classification: **structurally required** deviation.
- **Item 3, the aliasing guard — done by the prompt on 2026-09-04** (`c88776f`).

The prompt is therefore *Complete*, not *Blocked*. Its commit template for the "invariant holds"
branch was not used verbatim, because the work landed in three commits over two days (`c88776f`,
`5e2b208`, and `69cae4a`); the template's bullet
about `remove_Rayleigh_trivial` pruning is the one that would have been wrong.


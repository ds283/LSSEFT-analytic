# Log NN — <title>

**Prompt:** `prompts/pre-python-migration-fixes/NN-<slug>.md`
**Executed:** <YYYY-MM-DD>
**Branch:** <branch>
**Commit:** <sha> — `<subject line>`
**Parent commit:** <sha>
**Status:** Complete / Partial / Abandoned

---

## 1. What this prompt was for

Two or three sentences. Assume the reader has not read the prompt.

## 2. What was changed

A file-by-file account. For each file: what changed and why. Include the new names of anything
introduced. Be specific enough that a reader can follow the change without opening a diff — this
log is meant to replace the reconciliation cost, not add to it.

| File | Change | Notes |
|---|---|---|
| | | |

New files:

| File | Purpose |
|---|---|
| | |

Deleted files:

| File | Why |
|---|---|
| | |

## 3. Divergences from the prompt

**This is the most important section.** For every point where the shipped code differs from what
the prompt asked for, add an entry and classify it. If there were none, say "None" explicitly —
do not leave the section empty.

### 3.1 Structurally required

Changes the prompt's instruction could not accommodate.

> **D-1 — <short title>**
> **Prompt asked:** …
> **Shipped:** …
> **Obstacle:** the concrete thing that forced it — a compiler diagnostic, an API shape, a measured
> behaviour. Quote it.
> **Why this is minimal:** why no smaller deviation would have worked.

### 3.2 Implementation choices

Changes where more than one workable option existed.

> **D-2 — <short title>**
> **Prompt asked:** …
> **Shipped:** …
> **Options considered:** at least the one taken and the leading alternative.
> **Criterion used:** …
> **Trade-off a later reader might weigh differently:** state it honestly. A reader must be able to
> *disagree on the merits*, not merely wonder what happened.

### 3.3 Unintended drift

Changes that were neither asked for nor forced. Say so plainly.

> **D-3 — <short title>**
> **What drifted:** …
> **How it was noticed:** …
> **Disposition:** kept (and why it is harmless) / reverted / left for a follow-up issue ID.

## 4. Verification

What was run, and the actual numbers. Not "tests pass" — the counts, the timings, the md5s.

| Check | Expected | Observed | Verdict |
|---|---|---|---|
| Build | clean at `-std=c++17` | | |
| Kernel count | 101 | | |
| `compute_*` name set | identical to baseline | | |
| Integrand signature multiset | identical to baseline | | |
| Counterterm map (canonicalised) | identical to baseline | | |
| Warning set | identical to baseline | | |
| Wall clock | ~43 s | | |

Include the exact commands run, so they can be repeated.

```bash
```

## 5. Behaviour that intentionally changed

If the prompt was *supposed* to change something observable, record before and after here, with
evidence. If nothing was supposed to change, write "Nothing — this change is behaviour-preserving,
verified as in §4."

## 6. Issues opened, closed or updated

Cross-reference `IMPLEMENTATION_STATE.md` §3/§4 by ID.

| ID | Action | Detail |
|---|---|---|
| | | |

## 7. Notes for whoever comes next

Anything that surprised you, anything a follow-on prompt should know, anything you looked at and
deliberately did not touch. Include dead ends: knowing what does *not* work is worth as much as
knowing what does.

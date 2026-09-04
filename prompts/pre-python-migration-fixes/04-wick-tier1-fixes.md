# Prompt 04 — Wick contraction Tier-1 fixes

You are working in `~/Documents/Code/LSSEFT-analytic`. **Read**
`prompts/pre-python-migration-fixes/README.md` and `RECONCILIATION.md` first, and
`logs/03-determinism.md` for the state of the generated-output diff.

## Objective

Fix three strict bugs in the Wick-contraction machinery. All three are currently dormant, two of
them because they exactly mask each other. All three would wake as soon as the code is extended to
a third external leg, to a three-field block, or to a configuration where a cluster cannot close
its own delta function.

This is study §7.1 Tier 1 and §9 Phase −1 item 3.

## The single most important instruction

**Fixes (ii) and (iii) mutually mask each other and must land in the same commit.**

Fix (ii) alone makes four previously unreachable branches reachable. Four of those branches end in
`break` rather than `continue` (that is bug (iii)), and each `break` truncates the Wick product at
that contraction. The study measured that fixing (ii) alone would truncate **678 of 776** Wick
products — silently, producing wrong physics that still runs to completion.

Applying (ii) without (iii) is **worse than applying neither**. If you cannot land both, land
neither, and say so.

## Preconditions

- Prompts 01-03 complete; `baseline/pre-fix` tag exists; `validation/` harness works.
- Working tree clean. New branch.

## The three fixes

All three live in `lib/detail/contractions.{h,cpp}`. Line numbers are for `master` @ `cf9cb02`;
they may have shifted slightly after prompts 01-03, so anchor on the quoted text.

### (i) `graph::add_edge` records a directed edge

`lib/detail/contractions.cpp:142-151`:

```cpp
void graph::add_edge(size_t source, size_t dest)
  {
    this->vertices.insert(source);
    this->vertices.insert(dest);

    // insert source -> dest edge
    auto& dest_set = this->edges[source];
    dest_set.insert(dest);
  }
```

`is_connected()` (`:179-194`) walks *forward* from `*vs.begin()`, so this is a directed-reachability
test. Vertices are cluster (external-leg) ids.

For N = 2 the test is accidentally correct: the field list is built cluster-by-cluster
(`contractions.h:333-342`) and `enumerate_contractions` always takes `ivs_copy[0]` as the source
(`contractions.cpp:116`), so every edge runs from a lower cluster id to a higher one, and forward
reachability from the lowest vertex is correct for two vertices.

For N ≥ 3 it is wrong. The study replayed the tree-level bispectrum
⟨δ₁(k₁) δ₁(k₂) δ₂(k₃)⟩ and found that of the three cyclic assignments of the second-order kernel,
the `(1,1,2)` case produces edges `{0→2, 1→2}` — undirected that is the path 0–2–1, but walking
forward from vertex 0 reaches only 2, so vertex 1 is never visited and **both** contractions are
discarded. One of the three terms of B_tree is lost silently, and *which* term is lost depends on
the order the legs were declared.

**Fix:** also insert the reverse edge.

```cpp
    // also insert edge going the other way, since we treat edges as unoriented
    // (we only care about the graph as a means to test connectedness)
    auto& src_set = this->edges[dest];
    src_set.insert(source);
```

This is exactly what the `tree-bispectrum` branch already does — see
`git show tree-bispectrum:lib/correlators/detail/contractions.cpp` around line 121. Update the
class comment at `contractions.h:103-104` ("we track orientation of edges but this information
isn't really used"), which is no longer accurate.

### (ii) `evaluate_Wick_contractions` confuses field symbols with momenta

`lib/detail/contractions.h:474-549`.

The two containers involved are keyed by **momenta**:

- `unassigned[i]` is populated from `clusters[i].get_momenta()` at `:572`;
- `mma_map[clust][iv.get_momentum()]` is written at `:462-463` and `:396`.

But the lookups use `get_symbol()`, which returns the **field type symbol**. In this model every
initial value is created by `sf.make_initial_value("delta")` (`main.cpp:236-238`), so
`get_symbol()` is literally `delta` for every field while the momenta are `q0`, `q1`, … The lookups
therefore can never succeed.

Four sites to change:

| Line | Current | Should be |
|---|---|---|
| `:495` | `unassigned[left_clust].find(left_sym)` | `find(left_mom)` |
| `:496` | `unassigned[right_clust].find(right_sym)` | `find(right_mom)` |
| `:517` | `mma_map[left_clust][left_sym] = ...` | `mma_map[left_clust][left_mom] = ...` |
| `:525` | `mma_map[right_clust][right_sym] = ...` | `mma_map[right_clust][right_mom] = ...` |
| `:531` | `mma_map[left_clust].find(left_sym)` | `find(left_mom)` |
| `:539` | `mma_map[right_clust].find(right_sym)` | `find(right_mom)` |

**Note that the `tree-bispectrum` branch fixes only the first four.** It leaves `:555` and `:563`
(its equivalents of `:531` and `:539`) using `left_sym`/`right_sym`, so on that branch the
momentum-preference logic is *still* dead. Do not copy the branch wholesale — see
`RECONCILIATION.md` §2.3(D). The study's measured `t1_simple = 678` result can only be reached by
fixing all six.

`left_sym` and `right_sym` are still needed — they are the field labels that go into
`cfs::Pk(l, r, momentum)` at `:503-505`. Keep those uses.

Consequences of this fix, which you should expect to observe:

- The "we have a choice which momentum to use" preference logic at `:529-544` becomes live. The
  study measured it firing for **678 of 776** contractions.
- The two recovery branches at `:512-527`, which write a rewriting rule for a contraction with one
  unassigned endpoint, remain unexercised (`left_unassigned`/`right_unassigned` stay at zero,
  because `unassigned` is empty by the time this runs in every two-point case). Those are the
  branches an *n*-point function and a three-field block will need, and they will still be untested
  code when those cases first run. **Say this in the log** — it is a known, deliberate gap.
- `ERROR_COULD_NOT_EVALUATE_WICK_CONTRACTION` at `:499` becomes a live guard rather than dead code.

### (iii) `break` where `continue` is meant

`lib/detail/contractions.h`, inside `for(const auto& prod : gp)`: lines `518`, `526`, `535`, `543`.

Each contraction contributes one power-spectrum factor to the Wick product, so breaking out of the
loop truncates the product to the factors accumulated so far. Only the final fall-through path at
`:547` continues correctly, which is precisely why the current output is right.

**Fix:** all four `break` → `continue`.

## Why this is expected to be regression-free

The study verified it: with (i)+(ii)+(iii) applied, regenerating reproduces the published 101
integrands exactly — identical multiset of integrand × Wick-product signatures. The reason is that
`loop_integral::match_Wick_to_Rayleigh()` (`lib/loop_integral.cpp:168`) re-canonicalises the `Pk`
arguments against the loop and Rayleigh momenta afterwards, washing out the choice downstream.

**That is a claim to be demonstrated, not assumed** (issue I-04). Your verification below is what
turns it into a fact for this repository at this commit.

## Instrumentation you must add temporarily

Before and after the fix, count how often each branch of `evaluate_Wick_contractions` is taken over
a full run. Add counters for:

| Counter | Branch |
|---|---|
| `both_unassigned` | the throw at `:498-499` |
| `left_unassigned` | `:512-519` |
| `right_unassigned` | `:520-527` |
| `t1_simple` | `:531-536` |
| `t2_simple` | `:539-544` |
| `fallthrough` | `:547` |

Also count contraction groups and total contractions.

Expected, from the study:

| Build | left_unassigned | right_unassigned | t1_simple | t2_simple | fallthrough |
|---|---|---|---|---|---|
| before (as committed) | 0 | 0 | 0 | 0 | 776 |
| after (i)+(ii)+(iii) | 0 | 0 | **678** | 0 | 98 |

with 390 contraction groups and 776 contractions. **These are the study's numbers, not
independently verified during planning.** If yours differ, that is a finding — record the actual
numbers and investigate before concluding the fix is correct.

Also verify the study's key-confusion claim directly, once, with a print such as:

```
[INSTR-KEY] left_sym = delta ; left_mom = q0 ;
            unassigned[clust] = { } ; mma_map[clust] keys = { q0 }
```

**Remove the instrumentation before committing**, or gate it behind a compile-time flag that is off
by default. If you gate it, say so and make sure the default build is unaffected. Put the *numbers*
in the log, not the instrumentation in the tree.

## Explicitly out of scope

- Tier 2: the spanning-tree loop assignment, `assign_external_momenta`'s `labels.size() > 2` skip
  (`contractions.h:376`), the combinatorial pruning in `enumerate_contractions`. The
  `double_factorial(num-1)` guard belongs to prompt 05.
- Tier 3: anything for N ≥ 3 beyond these three fixes.
- The `Bk` placeholder and three-field blocks.

Note in the log that `assign_external_momenta`'s comment says "more than one" while the code says
`> 2`, and that the study measured the unassigned set as always of size exactly 1 at that point
across 780 calls — so neither the skip nor the size-2 path has ever run. Do not fix it here; it is
Tier 2 and belongs with the spanning-tree work in the port.

## Verification

1. **Branch counters before and after** — the table above, with your actual numbers.
2. **Functional equality with `baseline/pre-fix`** via `validation/compare_autogenerated.py`:
   identical signature multiset, identical set of 135 `compute_*` names, identical warning set.
   This is the gate. If it fails, the fix is not regression-free in this repository and you must
   stop and report rather than adjust anything to make it pass.
3. **Textual diff of `autogenerated/`** against the post-prompt-03 tree. After prompt 03 this
   should be readable. Ideally it is empty. If it is not, explain every difference.
4. **Counterterm map** unchanged after canonicalisation.
5. Wall clock still ≈ 43 s.
6. Re-run the 2018 comparison — still a functional match.

## Deliverables

- The three fixes in `lib/detail/contractions.{h,cpp}`, in **one** commit.
- The stale comment at `contractions.h:103-104` corrected.
- `prompts/pre-python-migration-fixes/logs/04-wick-tier1-fixes.md`
- `IMPLEMENTATION_STATE.md` updated; issue I-04 closed (with the demonstration) or updated;
  issue I-07 closed.

## Log requirements

Use `logs/TEMPLATE.md`. Additionally:

- The before/after branch-count table with **your** numbers, next to the study's, and a comment if
  they differ.
- The `[INSTR-KEY]` evidence that the lookups could not previously succeed.
- An explicit statement that the two recovery branches (`left_unassigned`, `right_unassigned`)
  remain unexercised even after the fix, and that they are the branches the *n*-point and
  three-block cases will first exercise — untested.
- Confirmation that all six `_sym` → `_mom` sites were changed, listed individually, and that the
  `left_sym`/`right_sym` uses in the `cfs::Pk(l, r, ...)` construction were correctly retained.
- Whether the instrumentation was removed or gated.
- Anything you noticed about the ordering of `Pk` arguments changing (the choice of momentum) even
  though the final result did not — that is the interesting middle of this change and a future
  reader will want it.

## Process

1. `IMPLEMENTATION_STATE.md`: prompt 04 → *In flight*.
2. Instrument, measure the "before" numbers.
3. Apply **all three** fixes.
4. Measure the "after" numbers, remove/gate the instrumentation, verify.
5. Log, update state, one commit:

```
Fix three strict bugs in Wick contraction enumeration

These are dormant for the two-point function and would wake for N >= 3 or
for a three-field block. Two of them mask each other exactly, so they must
land together: fixing the momentum keying without the break/continue fix
would truncate <N> of <M> Wick products silently.

- graph::add_edge now records edges in both directions; is_connected walks
  forward only, so the directed form is an incorrect connectivity test for
  three or more clusters (it loses both contractions of the (1,1,2) cluster
  configuration, i.e. one of the three cyclic terms of the tree bispectrum)
- evaluate_Wick_contractions now keys 'unassigned' and 'mma_map' lookups by
  momentum rather than by the field type symbol; both containers are keyed
  by momentum, so all six lookups previously could not succeed and four
  early-exit branches were unreachable
- four 'break' statements that truncate the Wick product become 'continue'

Branch counts over a full run, before -> after:
  fallthrough <N> -> <N>, t1_simple 0 -> <N>

Verified functionally unchanged against baseline/pre-fix: identical
signature multiset, identical 135 compute_* names, identical warning set.

Refs: prompts/pre-python-migration-fixes/04-wick-tier1-fixes.md

Co-Authored-By: Claude Opus 5 <noreply@anthropic.com>
```

## If verification fails

If the signature multiset changes, **do not** adjust the fix to make it match, and do not revert
just fix (ii) or just fix (iii). Stop, keep the branch, record the observed difference in detail
(which signatures, which kernels, which contraction groups), mark prompt 04 *Blocked*, raise an
issue, and report to the user. A genuine change here means the study's regression-free result does
not hold in this repository state, and that is a physics question, not an implementation one.

# Log 01 — Remove Boost and make the build reproducible

**Prompt:** `prompts/pre-python-migration-fixes/01-deboost-and-build.md`
**Executed:** 2026-09-04
**Branch:** `pre-python-migration-fixes/01-deboost-and-build`
**Commit:** `2e75f7f2c6927a1dc12314c5fa60de607fe96646` — `Remove Boost dependency and move to C++17`
**Parent commit:** `4657672740a232a403d1c35c06adb156b5ceabc9`
**Status:** Complete

---

## 1. What this prompt was for

`LSSEFT-analytic` had no working binary: Boost was not installed on this machine and the two
committed binaries were the wrong architecture. This prompt removed Boost entirely, moved the
project to C++17 (Boost's last remaining hard build dependency), and added a reproducible
build/run script pair, so that the program can be built and run with only a C++17 compiler and
`pkg-config ginac`. It is a purely mechanical, behaviour-preserving change — no algebra, no
contraction/reduction logic, and no emitted-output content was touched.

## 2. What was changed

| File | Change | Notes |
|---|---|---|
| `services/symbol_factory.h` | `boost::optional<std::string>` → `std::optional<std::string>`, `boost::none` → `std::nullopt`, drop the Boost include | textual substitution; `std::optional` supplies `operator<` needed by the `std::map` key |
| `services/symbol_factory.cpp` | same substitution in the three function signatures (`make_symbol`, `make_vector`, `make_initial_value`) | `if(latex_name)` / `*latex_name` usage is identical for `std::optional` |
| `services/argument_cache.h` | `boost::filesystem::path` → `std::filesystem::path`, `#include <filesystem>` | textual substitution |
| `services/argument_cache.cpp` | Rewrote the constructor as a hand-rolled `argv` scan; replaced `boost::filesystem::path`/`absolute` in the accessor definitions | see §3.2 D-1 for the parser design |
| `backends/LSSEFT.h` | `boost::filesystem::path` → `std::filesystem::path`; `boost::posix_time::ptime now` → `utc_timestamp now`; `#include <filesystem>` + `#include "utilities/timestamp.h"` | |
| `backends/LSSEFT.cpp` | Same substitutions in the constructor, `make_output_path`, and every `boost::filesystem::path` argument/return type; added explanatory comments at the two protected string-literal sites (`:873`, `:1160` after edits) | the two literals themselves are **untouched** — see §4 |
| `utilities/formatter.h` | `boost::timer::nanosecond_type` → a new file-scope `using nanosecond_type = std::uint64_t;`; dropped the Boost include; added `#include <string>` (was previously received transitively through Boost) | |
| `utilities/formatter.cpp` | `boost::timer::nanosecond_type` → `nanosecond_type` throughout `format_time` | arithmetic and formatting logic byte-for-byte unchanged |
| `instruments/timing_instrument.h` | `boost::timer::cpu_timer timer` member → `std::chrono::steady_clock::time_point start_time{now()}` + `stop_time`; dropped Boost include; dropped the pointless self-include `#include "timing_instrument.h"` | see §3.3 D-3 |
| `instruments/timing_instrument.cpp` | `.stop()`/`.elapsed().wall` → capture `stop_time` at destruction and `duration_cast<nanoseconds>` the difference, cast to `nanosecond_type` | functionally identical: both start timing at construction and read wall-clock elapsed time once, at destruction |
| `shared/error.cpp` | `boost::posix_time::ptime`/`to_simple_string` → `utc_timestamp{}.to_string()` in all four methods (`error`, `warn`, `info`, `announce`); dropped the Boost include; **added `#include <iostream>`** | this is the one compile failure predicted by `RECONCILIATION.md` §1 — confirmed, see §4 |
| `CMakeLists.txt` | `CMAKE_MINIMUM_REQUIRED` 3.0 → 3.16; `CMAKE_CXX_STANDARD` 14 → 17 + `CMAKE_CXX_STANDARD_REQUIRED ON`; removed `FIND_PACKAGE(Boost ...)` and both `${Boost_*}` references; added `utilities/timestamp.h` to `UTILITIES_FILES` | |
| `cmake/CompilerFlags.cmake` | `CMAKE_MINIMUM_REQUIRED` 3.0 → 3.16 | the RELEASE/DEBUG-only warning suppressions were **not** touched — see §3.2 D-2 |

New files:

| File | Purpose |
|---|---|
| `utilities/timestamp.h` | Header-only `utc_timestamp` class: captures UTC time at construction, formats as `"YYYY-Mmm-DD HH:MM:SS"` via a hard-coded 12-entry month table (not `strftime("%b")`, which is locale-dependent), reproducing `boost::posix_time::to_simple_string()`'s output shape at second resolution |
| `validation/build.sh` | Reproducible out-of-tree CMake configure+build, `pkg-config ginac` + system compiler only, idempotent, defaults to `<repo>/build-validation` |
| `validation/run.sh` | Runs the canonical published-output configuration (`--no-auto-symmetrize --symmetrize-22 --counterterms --output <dir>`), capturing stdout+stderr to `<output-dir>.log` alongside the output tree |
| `.gitignore` | Ignores `/build-validation/`, `/build-verify/`, `/validation/out/`, `.DS_Store` — none of these existed before this prompt, and nothing was previously ignored |

Deleted files: none.

## 3. Divergences from the prompt

### 3.1 Structurally required

None. The de-Boost was exactly as mechanical as `RECONCILIATION.md` §1 predicted: one missing
`#include <iostream>` in `shared/error.cpp` (received transitively through
`boost/date_time.hpp`), and nothing else.

### 3.2 Implementation choices

> **D-1 — Hand-rolled argument parser shape**
> **Prompt asked:** a hand-rolled `argv` scan covering the ten switches in `services/switches.h`,
> preserving defaults, `--output`/`--output=`/`-o` forms, absolute-ising relative paths, and a
> loud failure on an unrecognized option.
> **Shipped:** a single left-to-right `for` loop over `argv[1..argc)` with a chain of `if`/`continue`
> tests per recognized spelling, calling `[[noreturn]]` helpers `unrecognized_option` /
> `missing_value` on failure, and a hand-written `print_help()` mirroring the same switch list.
> **Options considered:** (a) a small table-driven dispatcher keyed by string (a
> `std::map<std::string, std::function<...>>`); (b) the flat `if`-chain shipped.
> **Criterion used:** the switch set is fixed and small (10 switches, none added or removed by this
> prompt), so a dispatch table would add a layer of indirection for no behavioural benefit; the
> flat chain reads top-to-bottom exactly like the table in `services/switches.h` it mirrors, which
> makes it easy to audit against that table.
> **Trade-off a later reader might weigh differently:** if the switch set grows in the port-facing
> future, the table-driven form would scale better and avoid a long `if`-chain. That is not a
> concern for an oracle whose switch set is deliberately frozen.
>
> Two narrowings relative to `boost::program_options`, exactly as the prompt anticipated and asked
> to be recorded:
> - **No long-option abbreviation guessing.** `boost::program_options` matches any unambiguous
>   prefix (`--counter` → `--counterterms`); this parser requires the full spelling. Reimplementing
>   prefix matching correctly (handling genuine ambiguity, e.g. a hypothetical `--c*` collision)
>   was judged not worth it for a fixed 10-switch set that every caller in this campaign invokes
>   with full spellings (see the canonical invocation in `README.md`).
> - **No `-opath` (short option with attached value).** Only `-o path` (space-separated) is
>   supported. `boost::program_options` supports both forms; the attached form is not used anywhere
>   in this repository or its scripts.
>
> **`--help` output shape.** Boost's `program_options` formatted a two-column table from the
> registered descriptions. The replacement `print_help()` hand-writes a similar two-column-ish
> layout (section headings, `--switch<TAB>description`) using the same `HELP_*` strings from
> `services/switches.h`, but does not attempt column alignment or byte-for-byte parity — no code
> anywhere parses `--help` output, so this is purely for a human reading the terminal.

> **D-2 — `CompilerFlags.cmake` release/debug-only warning suppressions left alone**
> **Prompt asked:** "The compiler-warning suppressions ... are only applied to
> `CMAKE_CXX_FLAGS_RELEASE`/`_DEBUG`, so they vanish in a default (no-build-type) configure. If you
> fix that, record it as an implementation choice."
> **Shipped:** left `cmake/CompilerFlags.cmake` untouched apart from the minimum-CMake-version bump.
> **Options considered:** (a) also apply the suppressions to `CMAKE_CXX_FLAGS` unconditionally so
> they take effect for a no-build-type configure; (b) leave as-is and always pass
> `-DCMAKE_BUILD_TYPE=Release` (or `Debug`) explicitly.
> **Criterion used:** the prompt scope is Boost removal and C++17, not a general build-flags cleanup;
> `validation/build.sh` always passes `-DCMAKE_BUILD_TYPE=Release` explicitly, so the gap never
> bites this campaign's own tooling. Fixing it would be an unrelated, unrequested change to
> warning-suppression scope.
> **Trade-off a later reader might weigh differently:** a bare `cmake .. && make` with no build type
> (which a newcomer might well run) will see the `-Wno-inconsistent-missing-override` etc. warnings
> from GiNaC headers that the suppressions exist to hide. That is pre-existing behaviour, not a
> regression from this prompt.

### 3.3 Unintended drift

> **D-3 — Removed the self-include in `instruments/timing_instrument.h`**
> **What drifted:** the prompt explicitly flagged `timing_instrument.h:33`
> (`#include "timing_instrument.h"` inside itself) as "harmless but pointless — removing it is
> fine, but say so in the log." This was removed while replacing the adjacent Boost include.
> **How it was noticed:** it sat directly next to the `boost/timer/timer.hpp` include being deleted.
> **Disposition:** kept removed — the prompt pre-authorized this specific removal.

## 4. Verification

All commands were run from `~/Documents/Code/LSSEFT-analytic` on the branch above, using the
project's own `validation/build.sh` and `validation/run.sh` for the final numbers (an earlier
throwaway `build-verify/` directory was used for iteration and then deleted; it is not part of the
deliverable).

| Check | Expected | Observed | Verdict |
|---|---|---|---|
| Build | clean at `-std=c++17`, no warnings that look like real problems | clean; zero compiler warnings emitted for any of the 24 translation units | ✅ |
| Wall clock | ≈ 43 s | 46.65 s real / 43.80 s user (a second, independent run measured 44.43 s real / 43.27 s user) | ✅ |
| Peak RSS | ≈ 30 MB | 31,801,344 bytes maxrss (≈ 30.3 MB); a second run measured 36,585,472 bytes (≈ 34.9 MB) | ✅ (within the "≈" the prompt itself used) |
| Kernel count (`double value_` in `kernel_integrands.cpp`) | 101 | 101 | ✅ |
| `compute_*` distinct name count | 135 | 135 | ✅ |
| `autogenerated/` file count | 22 | 22 | ✅ |
| `compute_*` name set vs 2018 reference | identical | `diff` against `~/Documents/Code/LSSEFT/autogenerated/Pk_expressions.cpp` returned no differences | ✅ |
| Warning set | exactly 3: q0-momentum, `bG3`, `bG3*b1_1` | exactly those 3, no `IR safety` / `Fabrikant` diagnostics | ✅ |
| Timestamp format | `YYYY-Mmm-DD HH:MM:SS`, e.g. `2026-Sep-04 01:23:45` | `pipeline_id()` returned `"2026-Sep-04 01:55:38"`; header line `// Generated at 2026-Sep-04 01:55:38` matches | ✅ |
| Switch parsing | `--help`, `--version` (no exit-0-no-tree change), `-o`, `--output=`, `--auto-symmetrize` accepted, unknown option fails loudly | all exercised, see below | ✅ |
| `grep -rn boost` over tracked source | exactly the two protected string literals in `backends/LSSEFT.cpp`, nothing else | exactly those two lines (`:873`, `:1160`); all explanatory comments were phrased with capital-`B` "Boost" so the case-sensitive grep does not pick them up — see §7 | ✅ |

Exact commands:

```bash
./validation/build.sh
./validation/run.sh                      # canonical config; writes validation/out/<UTC-ts>{,.log}

OUT=validation/out/<UTC-ts>
ls "$OUT/autogenerated" | wc -l                                              # 22
grep -c "double value_" "$OUT/autogenerated/kernel_integrands.cpp"           # 101
grep -o 'compute_[A-Za-z0-9_]*' "$OUT/autogenerated/Pk_expressions.cpp" | sort -u | wc -l   # 135
grep warning "${OUT}.log"                                                    # exactly 3 lines
diff <(grep -o 'compute_[A-Za-z0-9_]*' ~/Documents/Code/LSSEFT/autogenerated/Pk_expressions.cpp | sort -u) \
     <(grep -o 'compute_[A-Za-z0-9_]*' "$OUT/autogenerated/Pk_expressions.cpp" | sort -u)     # empty

./LSSEFT_analytic --help                 # prints usage, exit 0
./LSSEFT_analytic --version              # prints version only, exit 0, no output tree
./LSSEFT_analytic -o <dir> --counterterms                     # accepted (killed under timeout; no parse error)
./LSSEFT_analytic --output <dir> --counterterms               # accepted
./LSSEFT_analytic --output=<dir> --counterterms ...            # accepted
./LSSEFT_analytic --auto-symmetrize --counterterms -o <dir>    # accepted, runs the (much longer) default path
./LSSEFT_analytic --nonsense              # "LSSEFT-analytic: unrecognized option '--nonsense'", exit 1

grep -rn boost --include='*.h' --include='*.cpp' --include='*.txt' --include='*.cmake' . \
  | grep -v -E "build-clang|cmake-build-debug|mma\.txt|build-validation"
```

The Integrand-signature-multiset and canonicalised-counterterm-map checks referenced in the
template are not yet available: they are built by prompt 02's harness, which does not exist yet.
This prompt is the harness's hard precondition (`README.md` §"Recommended ordering"), so those
rows are intentionally left for prompt 02's own log to fill in against the baseline it archives.

## 5. Behaviour that intentionally changed

Nothing observable to a caller of the canonical invocation. Two narrow, explicitly-authorized
behavioural narrowings in the argument parser are recorded above as implementation choices (D-1):
no long-option abbreviation guessing, and no `-opath` attached-value form. Neither is exercised by
`README.md`'s canonical invocation or by any script in this repository.

## 6. Issues opened, closed or updated

No issue IDs in `IMPLEMENTATION_STATE.md` §3 name prompt 01 as owner, so none were closed. No new
issues were opened — the de-Boost went exactly as `RECONCILIATION.md` §1 predicted, with no
surprises worth a tracked issue.

## 7. Notes for whoever comes next

- **The case-sensitivity of the `grep -rn boost` acceptance check matters.** The prompt requires
  both (a) a short comment at each protected string-literal site explaining why it must not be
  touched, and (b) that `grep -rn boost` return *exactly* those two literal lines and nothing else.
  Comments that spell the word "boost" in lower case would themselves match and break check (b).
  The resolution used throughout this change: every explanatory comment refers to "Boost" with a
  capital B (as the project name conventionally is), and `grep -rn boost` (lower-case, the pattern
  the prompt specifies) does not match it. If a future sweep changes that grep to `-i`, it will
  need to re-word these comments.
- **`utc_timestamp` is deliberately not a drop-in `std::chrono` type.** It exists purely to
  reproduce one specific legacy string shape (`pipeline_id()`'s return value and every generated
  file's header line) exactly. Do not extend it into a general-purpose time utility; if the port
  or a later prompt needs more than "capture now, format as that one string," write something else.
- **`validation/out/` and `build-validation/` are gitignored, not archived.** Prompt 02 owns
  archiving the pre-fix baseline into `validation/baselines/pre-fix/`; nothing in this prompt writes
  there.
- **Dead end avoided:** initially wrote the explanatory Boost comments in lower case
  ("this 'boost::' is a string literal...") and only noticed the verification-7 conflict when
  re-running the exact `grep -rn boost` command from the prompt afterwards — it returned four
  lines instead of two. Re-worded to capitalized "Boost" rather than deleting the comments, since
  the prompt requires the comments to exist.

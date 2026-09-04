# Prompt 01 — Remove Boost and make the build reproducible

You are working in `~/Documents/Code/LSSEFT-analytic`, a C++14/GiNaC symbolic algebra program that
derives the one-loop redshift-space galaxy power spectrum and emits C++ for the numerical engine
`LSSEFT`. It is being prepared to serve as a differential oracle for a Python + SymPy port.

**Before you start, read** `prompts/pre-python-migration-fixes/README.md` and
`prompts/pre-python-migration-fixes/RECONCILIATION.md` in this repository. They contain measured
facts you will otherwise waste hours rediscovering.

## Objective

Remove Boost entirely and move the project to C++17, so that building the program requires only a
C++17 compiler and `pkg-config ginac`. This is a **purely mechanical, behaviour-preserving**
change. Nothing about the physics, the algebra or the emitted output may change.

The study's justification (§9, Appendix A.1): Boost is the last non-trivial build dependency, and
removing it is what makes the oracle runnable in CI and by an agent without a package-manager step.
Every Boost use has a direct C++17 standard-library equivalent.

## Why this must be first

There is **no working binary today**. Boost is not installed on this machine
(`/opt/local/include/boost`, `/usr/local/include/boost` and `/opt/homebrew/include/boost` all
absent), and the two committed binaries (`build-clang/LSSEFT_analytic`,
`cmake-build-debug/LSSEFT_analytic`) are x86_64 and link against a `libginac.6.dylib` that no
longer exists. Until this prompt is done, nothing in this campaign can be verified.

## Preconditions

- `pkg-config --modversion ginac` reports 1.8.10 (verified during planning).
- A C++17 compiler. Apple clang 21.0.0 was used during planning.
- Working tree clean. Create a branch before you start.

## Scope

### In scope

Only the Boost removal, the C++17 move, the build files, and a reproducible build/run script.

### Out of scope — do not touch

- Any algebra, contraction, reduction or backend logic.
- The `unordered_map` non-determinism (that is prompt 03).
- Any of the latent defects (prompts 04-06).
- `.idea/`, `build-clang/`, `cmake-build-debug/` — leave the stale build trees alone; do not try to
  make them work, and do not delete them without saying so in the log.

## The complete Boost inventory

Verified by grep against `master` @ `cf9cb02`. Ten source files plus `CMakeLists.txt`.

### (a) `boost::optional` → `<optional>`

| File | Sites |
|---|---|
| `services/symbol_factory.h` | `:33` include; `:57` `key_type = std::pair<std::string, boost::optional<std::string>>`; `:82`, `:90`, `:96` default arguments `= boost::none` |
| `services/symbol_factory.cpp` | `:44` `make_symbol`, `:151` `make_vector`, `:165` `make_initial_value` signatures |

`boost::optional` → `std::optional`, `boost::none` → `std::nullopt`. Textual substitution.

Note `symbol_factory.h:57` uses the optional as part of a `std::map` key, so it needs
`operator<` — `std::optional` provides it. Verify the map still compiles.

### (b) `boost::filesystem` → `<filesystem>`

| File | Sites |
|---|---|
| `services/argument_cache.h` | `:31` include; `:60`, `:63` return types; `:89`, `:92` members |
| `services/argument_cache.cpp` | `:106-107`, `:114-115` (`is_absolute`, `absolute`); `:134`, `:146` getters |
| `backends/LSSEFT.h` | `:37` include; `:180` constructor parameter; `:213` `make_output_path`; `:327` `root` member |
| `backends/LSSEFT.cpp` | `:33` include; `:442` constructor; `:601`, `:603-604` (`operator/`, `create_directories`) |

`boost::filesystem` is the direct ancestor of `std::filesystem`; this is a near-textual
substitution. `boost::filesystem::path` → `std::filesystem::path`,
`boost::filesystem::absolute` → `std::filesystem::absolute`,
`boost::filesystem::create_directories` → `std::filesystem::create_directories`.

Check the emptiness test used in `main.cpp:193` (`args.get_output_path().empty()`) still behaves
identically — `std::filesystem::path::empty()` exists and means the same thing.

### (c) `boost::posix_time` → a small `<chrono>` helper

| File | Sites |
|---|---|
| `shared/error.cpp` | `:32` include; `:37-38`, `:48-49`, `:60-61`, `:69-70` |
| `backends/LSSEFT.h` | `:38` include; `:347` `boost::posix_time::ptime now` member |
| `backends/LSSEFT.cpp` | `:32` include; `:446-447` |

**This is output-visible and must be replicated exactly.** `boost::posix_time::to_simple_string`
of a UTC `ptime` produces, for example:

```
2018-Jul-19 23:52:20
```

That string is written into the header of **every generated file**
(`backends/LSSEFT.cpp:1534`, `// Generated at <now_string>`) and is the **entire return value of
`pipeline_id()`** (`backends/LSSEFT.cpp:619`). `pipeline_id()` is a downstream identity string for
the `LSSEFT` database; changing its shape would be a silent, cross-repository breaking change.

Create `utilities/timestamp.h` (header-only is fine, ~20 lines) providing a UTC timestamp in
exactly that format. Two requirements:

1. The month abbreviation must be the English three-letter form regardless of locale — use a
   hard-coded 12-entry table, **not** `strftime("%b")`, which is locale-dependent.
2. Second resolution, UTC, matching `second_clock::universal_time()`.

`shared/error.cpp` also needs an explicit `#include <iostream>`: it currently receives it
transitively through `boost/date_time.hpp`, and **this is the one and only compile failure that
appears when Boost is removed** (measured during planning). Do not be surprised by it and do not
look for others; there are none.

### (d) `boost::timer` → `<chrono>`

| File | Sites |
|---|---|
| `utilities/formatter.h` | `:30` include; `:33` signature `format_time(boost::timer::nanosecond_type, unsigned int)` |
| `utilities/formatter.cpp` | `:34` definition; `:38-42` the five `constexpr` unit constants |
| `instruments/timing_instrument.h` | `:35` include; `:57` `boost::timer::cpu_timer timer` member |
| `instruments/timing_instrument.cpp` | `:44` `timer.stop()`; `:49` `timer.elapsed().wall` |

`boost::timer::cpu_timer` reports wall, user and system time; **only `.wall` is used**. Replace
with `std::chrono::steady_clock` and `using nanosecond_type = std::uint64_t;` in a small local
namespace. Preserve `format_time`'s output formatting exactly — it appears in every stage timing
line on stdout, and prompt 02 will capture those lines in the baseline.

While you are in `utilities/formatter.h`: it declares a function returning `std::string` but does
not include `<string>` (it currently gets it transitively from Boost). Add it.
`instruments/timing_instrument.h:33` also includes itself (`#include "timing_instrument.h"`);
that is harmless but pointless — removing it is fine, but say so in the log.

### (e) `boost::program_options` → a hand-rolled `argv` scan

`services/argument_cache.cpp:35-119` is the only site needing real code rather than substitution.
The option set is small and is defined in `services/switches.h`:

| Long switch | Takes value | Effect |
|---|---|---|
| `--version` | no | print name/version/copyright, **do not exit** |
| `--help` | no | print name/version (if not already printed) plus the option list, then `exit(EXIT_SUCCESS)` |
| `--auto-symmetrize` / `--no-auto-symmetrize` | no | set/clear `auto_symmetrize` (default **true**) |
| `--symmetrize-22` / `--no-symmetrize-22` | no | set/clear `symmetrize_22` (default **true**) |
| `--counterterms` / `--no-counterterms` | no | set/clear `counterterms` (default **false**) |
| `--output`, short `-o` | yes | absolute-ise and store in `output_root` |
| `--mathematica-output` | yes | absolute-ise and store in `output_mma` |

Required behaviour to preserve:

- Defaults come from the member initialisers in `services/argument_cache.h:73, 76, 82` — do not
  restate them in the parser.
- The `SWITCH_OUTPUT` constant is the Boost-style `"output,o"`; `SWITCH_OUTPUT_LONG` is `"output"`.
  Your parser should accept `--output <path>`, `--output=<path>` and `-o <path>`.
- Relative paths are made absolute at parse time (`argument_cache.cpp:107, 115`).
- An unrecognised option must be an error that stops the program. Boost's `parse_command_line`
  throws; a clear message on `stderr` plus `exit(EXIT_FAILURE)` is an acceptable equivalent — but
  say in the log that you chose it.
- `--version` alone must **not** exit; `main()` then falls through to the guard at `main.cpp:193`
  which exits because none of `--counterterms` / `--output` / `--mathematica-output` was given.
  Preserving this ordering matters.

Two deliberate narrowings you may take, **each of which must be recorded in the log as an
implementation choice**:

- Boost's `program_options` enables long-option *abbreviation guessing* by default (`--counter`
  would match `--counterterms`). Reimplementing that is not worth it; exact long-option matching
  is the sane replacement. Say so.
- Boost accepts `-opath` (short option with attached value). Supporting only `-o path` is fine.
  Say so.

The `--help` output was previously `boost::program_options`' formatted table
(`argument_cache.cpp:92`, printing `output_options`). You will have to hand-write an equivalent.
It need not match byte for byte; it must list every switch above with the `HELP_*` strings from
`services/switches.h`. Record the shape you chose.

### (f) The two `boost::` occurrences that must **not** be touched

`backends/LSSEFT.cpp:871` and `:1155`:

```cpp
outf << "    friend class boost::serialization::access;" << '\n';
...
     << "(const Mpc_units::energy& k, ..., const boost::optional<Pk_value>& Ptr_final)"
```

These are **string literals emitted into the generated C++** for the `LSSEFT` numerical engine to
compile. They are part of the output contract. Leave them exactly as they are. Add a short comment
at each site saying so, so a future de-Boosting sweep does not eat them.

### (g) Build files

`CMakeLists.txt`:

- `SET(CMAKE_CXX_STANDARD 14)` → `17`, and add `SET(CMAKE_CXX_STANDARD_REQUIRED ON)`.
  C++17 is **mandatory**: `std::optional` and `std::filesystem` are C++17.
- Remove `FIND_PACKAGE(Boost ...)` at `:16`, `${Boost_LIBRARIES}` at `:65`, `${Boost_INCLUDE_DIRS}`
  at `:70`.
- `CMAKE_MINIMUM_REQUIRED(VERSION 3.0)` at `:1` and `cmake/CompilerFlags.cmake:1` — CMake 4 rejects
  `< 3.5` outright and CMake 3.31 warns. Raise both to something current (3.16 is a safe floor).
- Add `utilities/timestamp.h` to `UTILITIES_FILES` so the CLion dummy target still lists every
  source file.
- Leave `cmake/BuildGiNaC.cmake` and the `FORCE_BUILD_GINAC` fallback alone.

The compiler-warning suppressions in `cmake/CompilerFlags.cmake` are only applied to
`CMAKE_CXX_FLAGS_RELEASE` / `_DEBUG`, so they vanish in a default (no-build-type) configure.
If you fix that, record it as an implementation choice.

### (h) A reproducible build and run script

Add `validation/build.sh` and `validation/run.sh` (or one script with subcommands — your call,
recorded). Requirements:

- `build.sh` configures and builds out of tree, using only `pkg-config ginac` and the system
  compiler. It must work from a clean checkout with no arguments.
- `run.sh` runs the canonical published-output configuration and nothing else by default:

  ```bash
  ./LSSEFT_analytic --no-auto-symmetrize --symmetrize-22 --counterterms --output <dir>
  ```

  capturing stdout and stderr to a log file alongside the output directory.
- Both must be idempotent and must not write anywhere outside the build/output directories they
  are given.

Do **not** commit a Boost shim directory. The study (Appendix A.2) explains why: fake Boost headers
on the include path will confuse anyone who later installs the real thing. The point of this prompt
is that no shim is needed.

## Verification

Run all of these and put the actual numbers in the log.

1. **Clean build** from a fresh build directory, no warnings that look like real problems.
2. **Run** the canonical configuration. Expected, all measured during planning:
   - wall clock ≈ 43 s (42.8 s user on an M-series Mac);
   - peak RSS ≈ 30 MB;
   - **101** occurrences of `double value_` in `autogenerated/kernel_integrands.cpp`;
   - **135** distinct `compute_*` names in `autogenerated/Pk_expressions.cpp`;
   - 22 files in `autogenerated/`;
   - exit status 0.
3. **Compare against the 2018 published reference** at `~/Documents/Code/LSSEFT/autogenerated/`
   (read-only; do not modify it):
   - the set of `compute_*` names must be **identical**. This was verified during planning and is
     a strong, cheap check:
     ```bash
     diff <(grep -o 'compute_[A-Za-z0-9_]*' ~/Documents/Code/LSSEFT/autogenerated/Pk_expressions.cpp | sort -u) \
          <(grep -o 'compute_[A-Za-z0-9_]*' <yourdir>/autogenerated/Pk_expressions.cpp | sort -u)
     ```
   - the kernel count must be 101 in both.
   - The `value_` strings will **not** match textually — expected, and explained in
     `RECONCILIATION.md` §3. Do not chase this. Prompt 02 builds the functional comparison.
4. **Warning set.** The run should emit exactly three diagnostics and no others:
   - `Kernel does not depend on available momentum vector q0`
   - `Empty RSD Pk group for filter pattern 'bG3'`
   - `Empty RSD Pk group for filter pattern 'bG3*b1_1'`

   In particular there must be **no** `Detected failure of IR safety` and **no**
   `Unevaluated Fabrikant integral`. If any of this changes, stop — you have broken something.
5. **Timestamp format.** Check that `autogenerated/pipeline_id.cpp` returns a string of exactly the
   form `2026-Sep-04 01:23:45`, and that the `// Generated at` header line matches. Compare the
   shape against the 2018 reference file, which contains `2018-Jul-19 23:52:20`.
6. **Switch parsing.** Exercise, at minimum: `--help`; `--version` alone (must exit 0 with no
   output tree); `-o dir`; `--output=dir`; `--auto-symmetrize` (expect a much longer run — you may
   skip running it to completion, but confirm the flag is read); an unknown option (must fail
   loudly).
7. **`grep -rn boost` over the tracked source** must return exactly the two protected string
   literals in `backends/LSSEFT.cpp` and nothing else. (Exclude `build-clang/`,
   `cmake-build-debug/`, `mma.txt`.)

## Deliverables

- Boost removed from all ten source files and from the build.
- `utilities/timestamp.h` added.
- `services/argument_cache.cpp` rewritten with a hand-rolled parser.
- `CMakeLists.txt` and `cmake/CompilerFlags.cmake` updated.
- `validation/build.sh`, `validation/run.sh`.
- `prompts/pre-python-migration-fixes/logs/01-deboost-and-build.md`, from `logs/TEMPLATE.md`.
- `IMPLEMENTATION_STATE.md` updated.

## Log requirements

Use `logs/TEMPLATE.md`. Beyond the template, this prompt specifically requires:

- A table of every Boost site and its replacement, so a reviewer can audit the substitution without
  re-grepping.
- The argument-parser narrowings (abbreviation guessing, `-opath`, `--help` formatting) recorded as
  **implementation choices** with the reasoning, per README §"Logs".
- The exact `format_time` and timestamp output shapes, with a sample line, so prompt 02 can encode
  them in the baseline comparison.
- Any file where removing Boost exposed a missing include, and what you added.
- Confirmation that `backends/LSSEFT.cpp:871` and `:1155` were left alone.

## Process

1. Update `IMPLEMENTATION_STATE.md`: prompt 01 → *In flight*, with the branch name.
2. Do the work.
3. Verify as above.
4. Write the log.
5. Update `IMPLEMENTATION_STATE.md`: prompt 01 → *Complete*, with the commit SHA; close or update
   any issue IDs you touched.
6. Commit everything in **one** commit:

```
Remove Boost dependency and move to C++17

- replace boost::optional with std::optional in symbol_factory
- replace boost::filesystem with std::filesystem in argument_cache and
  the LSSEFT backend
- replace boost::posix_time with utilities/timestamp.h, preserving the
  "YYYY-Mmm-DD HH:MM:SS" form written into pipeline_id() and every
  generated file header
- replace boost::timer with std::chrono::steady_clock
- replace boost::program_options with a hand-rolled argv scan covering
  the ten switches in services/switches.h
- add explicit <iostream> to shared/error.cpp and <string> to
  utilities/formatter.h, previously received through Boost headers
- raise CMake language standard to C++17 and drop the Boost package
- add validation/build.sh and validation/run.sh

The two boost:: occurrences in backends/LSSEFT.cpp are string literals
emitted into the generated code and are deliberately untouched.

Verified: 101 kernels, 135 compute_* functions with a name set identical
to the 2018 published output, three expected warnings, <N> s wall clock.

Refs: prompts/pre-python-migration-fixes/01-deboost-and-build.md

Co-Authored-By: Claude Opus 5 <noreply@anthropic.com>
```

Adjust the body to what you actually did — but keep it that specific.

## If something goes wrong

If the rebuilt program does **not** produce 101 kernels and the 135 published `compute_*` names,
stop. Do not adjust the algebra to make it match. Record what you observe in the log, mark prompt
01 *Blocked* in `IMPLEMENTATION_STATE.md`, raise an issue, and report to the user. A discrepancy
here means either the de-Boost was not behaviour-preserving or the repository state differs from
what this plan assumed, and both need a human decision.

# Competitive Programming Practice Repository

This repository contains my solutions to various competitive programming contests, primarily Codeforces rounds across Div. 4, Div. 3, and beyond. It also includes helpers for scaffolding new contests and VS Code integration.

## Repository Structure

Each contest is organized in its own folder, named after the contest and division. For example:

```
./contests
├── Codeforces Round 1003 (Div. 4)/
│   ├── a.cpp      # Problem A solution
│   ├── a.input    # Sample input for testing
│   ├── b.cpp
│   ├── b.input
│   ├── c1.cpp
│   ├── c1.input
│       ...
├── Codeforces Round 1013 (Div. 3)/
│   ├── a.cpp
│   ├── a.input
│   ├── b.cpp
│   ├── b.input
│       ...
```

Each `.cpp` file implements `solve()` and `main()` to handle one test case (or multiple, as described in the problem). Sample inputs (`*.input`) are provided for quick local testing.

## Required Tools

See [Required Tools](docs/required-tools.md) for the command-line tools needed to build, run, debug, and generate contest reports.

## Creating new contest folders

You can automatically create a new contest folder with boilerplate files using [new_contest.sh](scripts/new_contest.sh):

```bash
# Usage: scripts/new_contest.sh "<contest-folder-name>" <num-of-problems|last-problem-letter>
./scripts/new_contest.sh "Codeforces Round 1025 (Div. 3)" 13
# or
./scripts/new_contest.sh "Codeforces Round 1025 (Div. 3)" a
# or 
./scripts/new_contest.sh "Codeforces Round 1025 (Div. 3)" Z
```

## Contest Reporting

Use [contest_report.py](scripts/contest_report.py) to generate CSV reports from completed contests:

```bash
# Generate report for a specific contest
python3 scripts/contest_report.py "contests/Codeforces Round 1025 (Div. 3)" -o results.csv
```

See [Contest Reporting](docs/contest-reporting.md) for the required file header, valid tags, and CSV format.

## How to Build & Run

The root [Makefile](Makefile) is intended for quick local testing of contest files in
the current directory. It compiles with `clang++-22`, C++20, `-DLOCAL`, and a
generated local precompiled `bits/stdc++.h`.

The precompiled header is created on demand in the current contest directory under
`bits/`. Generated PCH files and binaries are ignored by git, so the repository only
tracks the scripts and templates needed to rebuild them.

See [Precompiled `bits/stdc++.h`](docs/precompiled-headers.md) for how the generated header works and why solution files should use `#include "bits/stdc++.h"`.

- **Run a problem sample:**
  ```bash
  make a
  ```
  This compiles `a.cpp` to `.build/a`, runs it with `a.input`, and writes the result to
  `a.out`.

- **Supported problem targets:**
  ```bash
  make a -> h
  ```

- **Clean generated files:**
  ```bash
  make clean
  ```
  This removes `.build/`, `bits/` and any `*.out` files in the current directory.

- **Prepare or rebuild the precompiled header:**
  ```bash
  make pch
  ```
  This creates `bits/stdc++.h` plus the compiler-specific precompiled header in the
  current directory. Generated `bits/` and `.build/` files stay out of git.

- **VS Code Task:** Use the built-in task **C/C++: build active file** to compile the current file through the Makefile. It writes executables to `.build/`.
- **VS Code Debug**: Launch via **lldb-dap: Launch** or **lldb-dap: Launch with input** in the debug panel. It runs the `.build/` binary, with the input variant reading `${fileBasenameNoExtension}.input`.


## Study Resources
I leverage the following platforms to learn algorithms and data structures:
* [CSES Problem Set](https://cses.fi/problemset/)
* [USACO Guide](https://usaco.guide/)
* [NEPS Academy](https://neps.academy/)
* [YouKn0wWho Academy](https://youkn0wwho.academy/)
* [CP31-sheet](https://www.tle-eliminators.com/cp-sheet)
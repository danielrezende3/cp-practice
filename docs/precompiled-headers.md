# Precompiled `bits/stdc++.h`

This repository builds contest solutions with a local precompiled `bits/stdc++.h` by default.

The normal path is:

```bash
make a
```

That command:

1. creates or refreshes `bits/stdc++.h` and `bits/stdc++.h.pch` in the current contest directory;
2. compiles `a.cpp` with `clang++-22`;
3. passes `-I. -include-pch bits/stdc++.h.pch`;
4. runs `.build/a` with `a.input`;
5. writes output to `a.out`.

## Include Style

Use quotes in solution files:

```cpp
#include "bits/stdc++.h"
```

Do not use angle brackets for this project:

```cpp
#include <bits/stdc++.h>
```

The quoted include makes the source use the local generated header under `./bits/`, matching the precompiled header passed by the Makefile.

New files created by `scripts/new_contest.sh` and the VS Code snippets already use the quoted include.

## Files Created Locally

The PCH setup creates generated files in the current contest directory:

```text
bits/stdc++.h
bits/stdc++.h.pch
bits/stdc++.h.pch.meta
.build/<problem>
*.out
```

These files are intentionally ignored by git.

## Rebuild The PCH

Usually, you do not need to run this manually because `make a` depends on `make pch`.

To force preparation before compiling:

```bash
make pch
```

To remove generated files and rebuild cleanly:

```bash
make clean
make pch
```

## VS Code

The VS Code build task runs:

```bash
make -f "${workspaceFolder}/Makefile" build-${fileBasenameNoExtension}
```

That goes through the same Makefile compile rule, so VS Code build and debug also use the precompiled header by default.

## Compiler

The Makefile defaults to:

```make
CXX = clang++-22
```

If `clang++-22` is not installed, install it or temporarily override the compiler:

```bash
make a CXX=clang++
```

If you override the compiler, run `make clean` first so the generated PCH matches the compiler and flags for the next build.

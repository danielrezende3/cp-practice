# Build and Run Solutions

The Makefile compiles C++20 solutions with `clang++` and uses a local precompiled `bits/stdc++.h` to keep repeated builds fast. It does not require a particular Clang version.

From a contest directory, point Make at the repository Makefile:

```bash
make -f ../../Makefile a
```

That command:

1. creates or refreshes `bits/stdc++.h` and `bits/stdc++.h.pch` in the current contest directory;
2. compiles `a.cpp` with the `clang++` available on `PATH`;
3. passes `-I. -include-pch bits/stdc++.h.pch`;
4. runs `.build/a` with `a.input`;
5. writes output to `a.out`.

## Source Include

Use quotes in solution files:

```cpp
#include "bits/stdc++.h"
```

The quoted include makes the source use the local generated header under `./bits/`, matching the precompiled header passed by the Makefile.

When the compiler does not provide GNU's non-standard header, the setup script uses the repository's portable standard-library fallback instead.

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

## Rebuild and Clean

Usually, you do not need to run this manually because `make a` depends on `make pch`.

To force preparation before compiling:

```bash
make -f ../../Makefile pch
```

To remove generated files and rebuild cleanly:

```bash
make -f ../../Makefile clean
make -f ../../Makefile pch
```

## VS Code

The VS Code build task runs:

```bash
make -f "${workspaceFolder}/Makefile" build-${fileBasenameNoExtension}
```

That goes through the same Makefile compile rule, so VS Code build and debug also use the precompiled header by default.

## Compiler Selection

The Makefile defaults to:

```make
CXX = clang++
```

The command resolves whatever unversioned `clang++` is available on `PATH`. You can override it for one invocation if needed:

```bash
make -f ../../Makefile a CXX=/path/to/clang++
```

If you override the compiler, run `make -f ../../Makefile clean` first so the generated PCH matches the compiler and flags for the next build.

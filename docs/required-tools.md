# Required Tools

This repository is built around a small Unix command-line toolchain.

## Required For Build And Run

Install these before using `make a`, `make pch`, or the VS Code build task:

- `bash`: runs the helper scripts.
- `make`: runs the project Makefile.
- `clang++-22`: compiles C++ solutions and builds the precompiled header.
- `awk`: used by `scripts/setup_pch.sh` to locate the system `bits/stdc++.h`.
- GNU core utilities: `mkdir`, `cp`, `rm`, `mktemp`, and `realpath`.

Check the required commands:

```bash
command -v bash
command -v make
command -v clang++-22
command -v awk
command -v realpath
```

Check the compiler version:

```bash
clang++-22 --version
```

## Required For Contest Reports

Contest reporting needs Python 3:

```bash
command -v python3
python3 --version
```

No third-party Python packages are required. The reporting script only uses the Python standard library.

## Optional For VS Code

VS Code integration uses the checked-in files under `.vscode/`.

For debugging, your VS Code installation needs an LLDB debugger that supports the `lldb-dap` debug type used by `.vscode/launch.json`.

The build task itself still uses the same Makefile path:

```bash
make -f "${workspaceFolder}/Makefile" build-${fileBasenameNoExtension}
```

So if command-line `make pch` and `make a` work, the VS Code build task is using the same toolchain.

## Generated Files

These tools generate local files such as:

```text
.build/
bits/
*.out
```

Those files are ignored by git and should not be committed.

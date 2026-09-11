# Contest Scaffolding

`scripts/new_contest.sh` creates a contest directory with one C++ source and one input file per problem.

From the repository root, pass the contest name and either the number of problems or the last problem letter:

```bash
./scripts/new_contest.sh "Codeforces Round 1025 (Div. 3)" 5
./scripts/new_contest.sh "Codeforces Round 1025 (Div. 3)" e
```

Both commands create problems `a` through `e` under `contests/Codeforces Round 1025 (Div. 3)/`.

Each generated `.cpp` file contains:

- the metadata fields used by contest reporting;
- the local `bits/stdc++.h` include;
- a `solve()` function and a multiple-test-case `main()` template.

Existing source and input files are preserved, so the command can safely fill in missing problem files in an existing contest directory. The accepted range is 1–26 problems, or a last letter from `a` through `z` (case-insensitive).

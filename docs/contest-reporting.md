# Contest Reporting

Use `scripts/contest_report.py` to generate a CSV summary for a completed contest.

## Required File Header

Each `.cpp` file must start with these two comment lines, in this order:

```cpp
// time-taken: 18
// tag: SOLVED
```

`time-taken` is the number of minutes spent on the problem.

Valid tags are:

- `SOLVED`
- `TIMEOUT`
- `PARTIAL`
- `NO_IDEA`

Files with missing or invalid metadata are skipped and reported in the terminal output.

## Generate A Report

From the repository root:

```bash
python3 scripts/contest_report.py "contests/Codeforces Round 1025 (Div. 3)" -o results.csv
```

The contest path can also be absolute, or relative to your current directory.

If `-o` is omitted, the default output file is:

```text
contest_results.csv
```

## CSV Columns

The generated CSV contains:

- `Contest`
- `File`
- `Time`
- `Tag`
- `Status`

`Status` is derived from the tag and time:

- `SOLVED_ON_TIME`: tag is `SOLVED` and time is 20 minutes or less
- `TIME_EXCEEDED`: tag is `SOLVED` and time is more than 20 minutes
- `NOT_SOLVED`: tag is anything other than `SOLVED`

## Example

```bash
python3 scripts/contest_report.py "contests/Codeforces Round 1074 (Div. 4)" -o round-1074.csv
```

Expected terminal output includes how many `.cpp` files were found, which files were skipped if metadata is invalid, and where the CSV was saved.

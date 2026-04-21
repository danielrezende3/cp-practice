import re
import csv
import argparse
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
pattern_tag = re.compile(r"^//\s*tag:(?:\s*(?P<tag>\S+))?$")
pattern_time = re.compile(r"^//\s*time-taken:(?:\s*(?P<time>\d+))?$")
VALID_TAGS = {"SOLVED", "TIMEOUT", "PARTIAL", "NO_IDEA"}


def extract_tag(line: str) -> str:
    possible_tag = pattern_tag.search(line.strip())
    if not possible_tag:
        raise ValueError("No tag found in line: usage '// tag: <tag>'")
    try:
        tag = possible_tag.group("tag")
    except IndexError:
        raise ValueError("Invalid tag format in line: usage '// tag: <tag>'")

    if tag is None:
        raise ValueError("Tag cannot be empty: usage '// tag: <tag>'")

    if tag in VALID_TAGS:
        return tag
    else:
        raise ValueError(f"Invalid tag '{tag}', usage: {VALID_TAGS}")


def extract_time(line: str) -> int:
    possible_time = pattern_time.search(line.strip())
    if not possible_time:
        raise ValueError("No time found in line: usage '// time-taken: <number>'")

    time_str = possible_time.group("time")
    if time_str is None:
        raise ValueError("Time value cannot be empty: usage '// time-taken: <number>'")

    try:
        time_taken = int(time_str)
    except ValueError:
        raise ValueError("Invalid time format in line: usage is '// time-taken: <number>'")

    return time_taken


def _collect_row(file: Path, contest_name: str) -> tuple[str, str, int, str, str]:
    lines = file.read_text(encoding="utf-8").splitlines()
    if len(lines) < 2:
        raise ValueError("File must contain at least two lines")
    first_two = lines[:2]

    time = extract_time(first_two[0])
    tag = extract_tag(first_two[1])
    
    if tag == "SOLVED" and time > 20:
        status = "TIME_EXCEEDED"
    elif tag == "SOLVED":
        status = "SOLVED_ON_TIME"
    else:
        status = "NOT_SOLVED"

    return (contest_name, file.name, time, tag, status)


def collect_rows(files: list[Path]) -> tuple[list[tuple[str, str, int, str, str]], list[tuple[str, str]]]:
    results = []
    skipped_files = []
    for file in files:
        try:
            contest_name = file.parent.name
            results.append(_collect_row(file, contest_name))
        except Exception as e:
            # Skip files that cause errors
            skipped_files.append((file.name, str(e)))
            continue
    return results, skipped_files


def save_to_csv(data: list[tuple[str, str, int, str, str]], filename: str):
    with open(filename, "w", newline="", encoding="utf-8") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Contest", "File", "Time", "Tag", "Status"])
        writer.writerows(data)


def resolve_contest_folder(contest_folder: str) -> Path:
    folder = Path(contest_folder)
    if folder.is_absolute():
        return folder

    cwd_folder = Path.cwd() / folder
    if cwd_folder.exists():
        return cwd_folder

    return REPO_ROOT / folder


def main():
    parser = argparse.ArgumentParser(description="Generate contest report from C++ files")
    parser.add_argument("contest_folder", help="Path to contest folder containing .cpp files")
    parser.add_argument("-o", "--output", default="contest_results.csv", help="Output CSV filename")

    args = parser.parse_args()

    folder = resolve_contest_folder(args.contest_folder)
    if not folder.exists():
        print(f"Error: Folder '{args.contest_folder}' does not exist")
        return

    cpp_files = list(folder.glob("*.cpp"))
    if not cpp_files:
        print(f"Error: No .cpp files found in '{args.contest_folder}'")
        return

    print(f"Found {len(cpp_files)} C++ files")
    rows, skipped_files = collect_rows(cpp_files)
    save_to_csv(rows, args.output)

    if skipped_files:
        print(f"\nThose files were skipped ({len(skipped_files)}/{len(cpp_files)}):")
        for file, error in sorted(skipped_files):
            print(f"- {file}: {error}")
    print(f"\nReport saved to {args.output}")


if __name__ == "__main__":
    main()

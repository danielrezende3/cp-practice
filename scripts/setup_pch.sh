#!/usr/bin/env bash
set -euo pipefail

target_dir="${1:-$PWD}"
cxx="${CXX:-clang++}"
cxxflags="${CXXFLAGS:--std=c++20 -O2 -Wall -Wextra -Wshadow -DLOCAL -I.}"
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
portable_header="$script_dir/portable_stdc++.h"
read -r -a flags <<<"$cxxflags"
version="$("$cxx" --version | head -n 1)"

mkdir -p "$target_dir/bits"

header="$target_dir/bits/stdc++.h"
if [[ "$version" == *[Cc][Ll][Aa][Nn][Gg]* ]]; then
  pch="$header.pch"
else
  pch="$header.gch"
fi
meta="$pch.meta"
signature="$version | $cxxflags"

if [[ -f "$pch" && -f "$meta" && "$(cat "$meta")" == "$signature" ]]; then
  exit 0
fi

tmp="$(mktemp)"
trap 'rm -f "$tmp"' EXIT
printf '#include <bits/stdc++.h>\n' >"$tmp"

system_header="$(
  { "$cxx" "${flags[@]}" -x c++ -H -fsyntax-only "$tmp" 2>&1 >/dev/null || true; } |
    awk '/bits\/stdc\+\+\.h$/ { print $2; exit }'
)"

if [[ -z "$system_header" || ! -f "$system_header" ]]; then
  system_header="$portable_header"
fi

system_header_real="$(realpath "$system_header")"
header_real="$header"
if [[ -f "$header" ]]; then
  header_real="$(realpath "$header")"
fi

if [[ "$system_header_real" != "$header_real" ]]; then
  cp "$system_header" "$header"
fi

"$cxx" "${flags[@]}" -x c++-header "$header" -o "$pch"
printf '%s\n' "$signature" >"$meta"

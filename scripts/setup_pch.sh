#!/usr/bin/env bash
set -euo pipefail

target_dir="${1:-$PWD}"
cxx="${CXX:-clang++-22}"
cxxflags="${CXXFLAGS:--std=c++20 -O2 -Wall -Wextra -Wshadow -DLOCAL -I.}"
read -r -a flags <<<"$cxxflags"
version="$("$cxx" --version | head -n 1)"

mkdir -p "$target_dir/bits"

header="$target_dir/bits/stdc++.h"
if [[ "${version,,}" == *clang* ]]; then
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
  "$cxx" "${flags[@]}" -x c++ -H -fsyntax-only "$tmp" 2>&1 >/dev/null |
    awk '/bits\/stdc\+\+\.h$/ { print $2; exit }'
)"

if [[ -z "$system_header" || ! -f "$system_header" ]]; then
  echo "Could not locate bits/stdc++.h with $cxx" >&2
  exit 1
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

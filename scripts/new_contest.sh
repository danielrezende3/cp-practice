#!/usr/bin/env bash
set -e

usage() {
  echo "Usage: $0 <contest-folder-name> <num-of-problems|last-problem-letter>"
  echo " e.g.: $0 \"Codeforces Round 1025 (Div. 3)\" 5"
  echo "       $0 \"Codeforces Round 1025 (Div. 3)\" e"
  exit 1
}

if [[ $# -ne 2 ]]; then
  usage
fi

contest="$1"
arg="$2"

if [[ "$arg" =~ ^[0-9]+$ ]]; then
  n=$arg
elif [[ "$arg" =~ ^[A-Za-z]$ ]]; then
  ascii=$(printf '%d' "'${arg^^}")
  n=$((ascii - 64))
else
  usage
fi

if ((n < 1 || n > 26)); then
  echo "Error: number of problems must be between 1 and 26."
  exit 1
fi

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
contest_dir="$repo_root/contests/$contest"

mkdir -p "$contest_dir"
pushd "$contest_dir" >/dev/null

for ((i = 0; i < n; i++)); do
  ascii=$((97 + i))
  letter=$(printf '%b' "\\x$(printf '%x' "$ascii")")
  
  if [[ ! -f "${letter}.input" ]]; then
    touch "${letter}.input"
  else
    echo "Skipping ${letter}.input (already exists)"
  fi
  
  if [[ ! -f "${letter}.cpp" ]]; then
    cat >"${letter}.cpp" <<'EOF'
#include "bits/stdc++.h" // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

const ll MOD = 1e9 + 7;

void solve() {
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;
  while (count--) {
    solve();
  }
}

EOF
  else
    echo "Skipping ${letter}.cpp (already exists)"
  fi
done

popd >/dev/null
echo "Created $n problems in $contest/"

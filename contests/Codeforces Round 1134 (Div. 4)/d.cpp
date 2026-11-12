#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

void solve() {
  // replace all occurrences of x in s with the previous letter of the alphabet.
  // cbad 1
  // cabc 2
  // bbab 3
  // aaaa
  //
  // cbad 0
  // cbac 1
  // caac 2
  ll n;
  string s;

  cin >> n >> s;
  vector<bool> ops(26, false);

  for (int i = 0; i < n / 2; i++) {
    char min_c = min(s[i], s[n - 1 - i]);
    char max_c = max(s[i], s[n - 1 - i]);

    for (char c = min_c; c < max_c; c++) {
      ops[c - 'a'] = true;
    }
  }

  ll ans = 0;
  for (bool op : ops) {
    if (op) ans++;
  }
  cout << ans << endl;
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

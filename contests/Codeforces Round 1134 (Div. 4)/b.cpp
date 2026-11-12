#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

void solve() {
  ll n;
  string s;
  cin >> n >> s;
  bool is_red = true;
  // the idea
  ll manual = 0;
  for (ll i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s[i] != 'R') {
      }
    }
  }
  cout << manual << endl;
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

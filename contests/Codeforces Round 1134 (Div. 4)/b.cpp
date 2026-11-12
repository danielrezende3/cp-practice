#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

/*
Initially, the pen writes in red. Each time the pen writes a letter, its color
switches automatically: after writing a red letter, it writes in blue, and after
writing a blue letter, it writes in red.

Before writing each letter, including the first one, you may also switch the
color of the pen manually: from red to blue or from blue to red.

so it compares with the last one not if it follows the pattern RBRBR

BBB
^
1 switch R -> B
BBB
 ^
but now the switch automatically changes to R
2 switches R->b
*/
void solve() {
  ll n;
  string s;
  cin >> n >> s;

  ll manual = 0;
  if (s[0] != 'R') manual++;

  for (ll i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) manual++;
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

#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

void solve() {
  // if it has the format that 0, x y, if y-x makes x,x,x then its valid
  vll a(3);
  cin >> a[0] >> a[1] >> a[2];

  sort(a.begin(), a.end());

  if (a[0] + 1 == a[1] && a[2] - 1 == a[1])
    cout << "YES";
  else
    cout << "NO";

  cout << "\n";
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

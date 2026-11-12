#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

void solve() {
  ll n;
  cin >> n;
  vll h(n);

  for (ll i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(ALL(h));

  vll new_h(n);
  ll l = 0, r = n - 1, ans = 0;
  for (ll i = 0; i < n; i++) {
    if (i % 2 == 0)
      new_h[l++] = h[i];
    else
      new_h[r--] = h[i];

    if (!(i >= 2 and h[i] == h[i - 2])) ans++;
  }

  cout << ans << endl;
  for (auto i : new_h) {
    cout << i << " ";
  }
  cout << '\n';
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

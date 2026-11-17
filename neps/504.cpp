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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll c, t;
  cin >> c >> t;
  vll r(c);

  for (ll i = 0; i < c; i++) {
    cin >> r[i];
    r[i] *= r[i];
  }
  ll ans = 0;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    ll curr = x * x + y * y;
    ll contidos = r.end() - lower_bound(ALL(r), curr);
    ans += contidos;
  }
  cout << ans << endl;
}
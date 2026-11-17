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

bool can(const vll& a, const ll k, const ld x) {
  ll ans = 0;
  for (ll r : a) {
    ans += (ll)(r / x);
    if (ans >= k) return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  ld l = 0, r = *max_element(ALL(a));

  while (r - l > 1e-7L) {
    ld mid = l + (r - l) / 2;

    if (can(a, k, mid))
      l = mid;
    else
      r = mid;
  }

  cout << fixed << setprecision(10) << l << '\n';
}
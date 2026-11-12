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

bool can(ll cap, const vll& a, ll x) {
  ll fuel = cap, prev = 0, n = (ll)a.size();

  for (ll i = 0; i < n; i++) {
    fuel -= a[i] - prev;
    if (fuel < 0) return false;

    fuel = cap;
    prev = a[i];
  }

  fuel -= x - prev;
  if (fuel < 0) return false;

  for (ll i = a.size() - 1; i >= 0; i--) {
    fuel -= x - a[i];
    if (fuel < 0) return false;

    fuel = cap;
    x = a[i];
  }

  fuel -= x;
  return fuel >= 0;
}

void solve() {
  ll n, x;
  cin >> n >> x;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll l = 0, r = 2 * x;

  while (l < r) {
    ll m = l + (r - l) / 2;
    if (can(m, a, x))
      r = m;
    else
      l = m + 1;
  }
  cout << l << '\n';
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

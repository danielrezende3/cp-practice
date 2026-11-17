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

bool can(const vector<tuple<ll, ll, ll>>& a, ll m, ll x) {
  ll ans = 0;

  for (auto [t, z, y] : a) {
    ll c = t * z + y;

    ll full = x / c;
    ll remaining = x % c;

    ll balloons = full * z + min(z, remaining / t);
    ans += balloons;

    if (ans >= m) return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll m, n;
  cin >> m >> n;

  vector<tuple<ll, ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    ll t, z, y;
    cin >> t >> z >> y;
    a[i] = {t, z, y};
  }
  ll l = 0, r = LLONG_MAX;

  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (can(a, m, mid))
      r = mid;
    else
      l = mid;
  }

  cout << r << endl;
  ll remaining = m;

  for (auto [t, z, y] : a) {
    ll cycle = t * z + y;

    ll full = r / cycle;
    ll partial = r % cycle;

    ll balloons = full * z + min(z, partial / t);

    ll count = min(remaining, balloons);

    cout << count << " ";
    remaining -= count;
  }
}
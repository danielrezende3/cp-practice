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
  ll n;
  cin >> n;

  vll v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  map<ll, ll> mp;
  ll l = 0;
  ll ans = 0;
  for (ll r = 0; r < n; r++) {
    if (mp.count(v[r]) and mp[v[r]] >= l) {
      l = mp[v[r]] + 1;
    }
    mp[v[r]] = r;
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
}
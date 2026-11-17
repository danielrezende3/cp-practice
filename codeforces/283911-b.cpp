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

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vll v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }
  while (k--) {
    ll val;
    cin >> val;
    auto it = upper_bound(ALL(v), val);
    cout << it - v.begin() << endl;
  }
}
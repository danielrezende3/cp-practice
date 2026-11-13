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

bool can(const vll* sanduiches, ll corte_cm, ll pedacos_target) {
  ll qnt_sands = 0;
  for (ll sand : *sanduiches) qnt_sands += sand / corte_cm;

  return qnt_sands >= pedacos_target;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vll v(k);
  for (ll i = 0; i < k; i++) {
    cin >> v[i];
  }

  ll l = 0, r = LLONG_MAX, ans = 0;
  while (l <= r) {
    ll m = l + (r - l) / 2;

    if (can(&v, m, n)) {
      ans = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  cout << ans << '\n';
}
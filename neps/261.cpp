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
  ll n, m;
  cin >> n >> m;

  vll range(n + 1);
  range[0] = LLONG_MIN;
  range[n] = LLONG_MAX;
  for (ll i = 1; i < n; i++) {
    cin >> range[i];
  }

  vll premiacoes(n);
  for (ll i = 0; i < n; i++) {
    cin >> premiacoes[i];
  }

  for (ll i = 0; i < m; i++) {
    ll val;
    cin >> val;
    auto it = lower_bound(ALL(range), val);
    if (*it == val)
      cout << premiacoes[it - range.begin()];
    else
      cout << premiacoes[prev(it) - range.begin()];

    cout << " ";
  }
}

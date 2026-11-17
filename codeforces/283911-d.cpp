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
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(ALL(v));

  ll k;
  cin >> k;
  while (k--) {
    ll l, r;
    cin >> l >> r;

    int lit = lower_bound(ALL(v), l) - v.begin();
    int rit = upper_bound(ALL(v), r) - v.begin();
    cout << rit - lit << endl;
  }
}
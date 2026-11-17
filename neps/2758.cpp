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

  ll n;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll q;
  cin >> q;
  while (q--) {
    ll val;
    cin >> val;
    auto it = lower_bound(ALL(a), val);
    if (it != a.end() and *it == val) {
      cout << it - a.begin() << endl;
    } else {
      cout << "X" << endl;
    }
  }
}
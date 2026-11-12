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
  cin >> n;

  multiset<ll> towers_ahead;
  for (ll i = 0; i < n; i++) {
    cin >> m;
    auto it = towers_ahead.upper_bound(m);

    if (it == towers_ahead.end()) {
      towers_ahead.insert(m);

    } else {
      towers_ahead.erase(it);
      towers_ahead.insert(m);
    }
  }

  cout << towers_ahead.size() << endl;
}
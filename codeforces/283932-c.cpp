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

bool can(ll n, ll x, ll y, ll z) { return z / x + z / y >= n - 1; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x, y;
  cin >> n >> x >> y;

  ll l = 0, r = (n - 1) * min(x, y);
  while (l < r) {
    ll mid = l + (r - l) / 2;

    if (can(n, x, y, mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << min(x, y) + r << endl;
}
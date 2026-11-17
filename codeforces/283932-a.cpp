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

bool can(ll w, ll h, ll n, ll x) {
  ll cols = x / w;
  ll rows = x / h;
  return cols > 0 and rows > (n - 1) / cols;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll w, h, n;
  cin >> w >> h >> n;
  ll l = 0, r = max(w, h) * n, ans = 0;
  while (l <= r) {
    ll mid = l + (r - l) / 2;

    if (can(w, h, n, mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
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

void solve() {
  ll n, k;
  cin >> n >> k;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k >= 2 or is_sorted(ALL(a))) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;
  while (count--) {
    solve();
  }
}

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

/*
k- 1= 7
k - 2= 6
k - 3= 5
k -a[3]=
distintas
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  set<ll> v;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    v.insert(x);
  }
  ll k;
  cin >> k;
  for (auto i : v) {
    ll complement = k - i;
    auto it = v.find(complement);
    if (it != v.end()) {
      cout << min(*it, i) << " " << max(*it, i) << '\n';
      return 0;
    }
  }
}
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

void solve() {
  ll n;
  string s;
  cin >> n >> s;
  ll dots = count(ALL(s), '.');
  if (s.find("...") != string::npos) {
    cout << 2 << '\n';
  } else {
    cout << dots << '\n';
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

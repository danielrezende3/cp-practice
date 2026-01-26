// time-taken:
// tag:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>

ll mex(vll& a) {
  ll n = a.size();
  vector<bool> present(n + 1, false);
  for (ll i = 0; i < n; i++) {
    if (0 <= a[i] && a[i] <= n) present[a[i]] = true;
  }
  for (ll i = 0; i <= n; i++) {
    if (!present[i]) return i;
  }
  return n + 1;
}

void solve() {
  ll n, value;
  cin >> n;
  set<ll> a;
  for (ll i = 0; i < n; i++) {
    cin >> value;
    a.insert(value);
  }
  ll prev = LLONG_MIN;
  ll res = 1;
  ll biggest = LLONG_MIN;
  for (auto i : a) {
    if (i == prev + 1)
      res++;
    else
      res = 1;

    biggest = max(biggest, res);
    prev = i;
  }
  cout << biggest << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int count;
  cin >> count;
  while (count--) {
    solve();
  }
  return 0;
}

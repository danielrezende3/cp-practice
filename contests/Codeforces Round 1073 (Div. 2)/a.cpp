// time-taken: 9
// tag:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, bool>> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i].first;
    if (i % 2 == 0) {
      a[i].second = true;  // red
    } else {
      a[i].second = false;  // blue
    }
  }
  sort(a.begin(), a.end());
  for (size_t i = 1; i < n; i++) {
    if (a[i].second == a[i - 1].second) {
      cout << "NO\n";
      return;
    } else {
      continue;
    }
  }
  cout << "YES\n";
}

int main() {
  int count;
  cin >> count;
  while (count--) {
    solve();
  }
  return 0;
}

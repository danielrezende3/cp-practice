// time-taken:
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
  vll a(n);

  ll max_value = LLONG_MIN;
  ll value;
  for (size_t i = 0; i < n; i++) {
    cin >> value;
    a[i] = value;
    max_value = max(value, max_value);
  };
  cout << n * max_value << "\n";
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

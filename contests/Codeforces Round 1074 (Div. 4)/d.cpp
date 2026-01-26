// time-taken:
// tag:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>

void solve() {
  ll n, m, h;
  cin >> n >> m >> h;
  vll original_values(n);
  for (ll i = 0; i < n; i++) {
    cin >> original_values[i];
  }

  ll b, c;
  vll memory = original_values;
  ll count_crashed = 0;
  vll crashed_count_each(n, 0);
  for (size_t i = 0; i < m; i++) {
    cin >> b >> c;
    b--;

    if (crashed_count_each[b] < count_crashed) {
      memory[b] = original_values[b];
      crashed_count_each[b] = count_crashed;
    }

    memory[b] += c;
    if (memory[b] > h) {
      count_crashed++;
    }
  }
  for (size_t i = 0; i < n; i++) {
    if (crashed_count_each[i] < count_crashed) {
      cout << original_values[i] << " ";
    } else {
      cout << memory[i] << " ";
    }
  }

  cout << "\n";
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

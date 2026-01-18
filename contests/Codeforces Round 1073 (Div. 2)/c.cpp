// time-taken:
// tag:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>

bool is_sortedd(const string& s) {
  // s == sorted(s)
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i - 1] > s[i]) return false;  // '1' > '0' detecta inversão
  }
  return true;
}

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  if (is_sortedd(s)) {
    cout << "Bob\n";
    return;
  }

  cout << "Alice\n";

  ll k = 0;
  for (char c : s)
    if (c == '0') k++;

  vector<ll> idx;
  // A: prefixo [0..k-1] que deveria ser 0, mas é 1
  for (ll i = 0; i < k; i++)
    if (s[i] == '1') idx.push_back(i + 1);

  // B: sufixo [k..n-1] que deveria ser 1, mas é 0
  for (ll i = k; i < n; i++)
    if (s[i] == '0') idx.push_back(i + 1);

  cout << idx.size() << "\n";
  for (ll i = 0; i < idx.size(); i++) {
    cout << idx[i] << " ";
  }
  cout << "\n";
}

int main() {
  int count;
  cin >> count;
  while (count--) {
    solve();
  }
  return 0;
}

// time-taken:
// tag:
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>

// In one turn, a player chooses a sequence of indices i1,i2,…,im
// (1≤i1<i2<…<im≤n) such that the characters at these positions form a
// non-increasing sequence (that is, si1≥si2≥…≥sim). The player then rearranges
// the characters at these positions to be sorted in non-decreasing order
// Formally, let the chosen characters consist of z zeros and o ones (where
// z+o=m). The move replaces the characters at positions i1,i2,…,im with a
// sequence of z zeros followed by o ones. A move is valid if and only if it
// strictly modifies the string s (which implies z≥1 and o≥1).

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
// A ideia é que eu tenho pelo menos dois numeros para dividir em cada jogada,
// então se eu tiver 0, eu não consigo fazer um split em que apareça outro valor
void solve() {
  ll n;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  ll res = mex(a);

  if (res == 0) {
    cout << "NO\n";
    return;
  }

  if (res == 1) {
    ll count_0 = 0;
    for (auto x : a)
      if (x == 0) count_0++;

    cout << (count_0 == 1 ? "YES\n" : "NO\n");
    return;
  }

  // res >= 2
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

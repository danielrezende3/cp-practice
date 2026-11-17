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
To maximize the number of rounds, choose the smallest distinct values:
r_1     = a + 0
r_2     = a + 1
r_3     = a + 2
...
r_(n-1) = a + (n - 2)

We only sum the first n-1 rounds because the final round
is allowed to reach or exceed L.

Split the sum into two parts:

S = a + (a+1) + (a+2) + ... + (a+n-2)

1. Constant part:
   S1 = a * (n - 1)

2. Increasing part:
   S2 = 0 + 1 + 2 + ... + (n - 2)

   Using the arithmetic series formula:
   sum(0..k) = k * (k + 1) / 2

   Substitute k = n - 2:
   S2 = (n - 2) * (n - 1) / 2

Final formula:
S = a * (n - 1) + (n - 2) * (n - 1) / 2

A candidate n is valid if:
- n <= b - a + 1 (enough distinct values)
- S < L (the game has not ended before the final round)

If we execute n-- before calculating S, the formula becomes:
S = a * n + n * (n - 1) / 2
*/

bool can(ll l, ll a, ll b, ll n) {
  if (n > b - a + 1) return false;

  ll sum = a * (n - 1) + (n - 2) * (n - 1) / 2;

  return sum < l;
}

void solve() {
  ll l, a, b;
  cin >> l >> a >> b;

  ll left = 1, right = b - a + 2;
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;

    if (can(l, a, b, mid))
      left = mid;
    else
      right = mid;
  }

  cout << left << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll p;
  cin >> p;
  while (p--) {
    solve();
  }
}
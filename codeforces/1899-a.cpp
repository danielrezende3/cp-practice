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
the idea is to know that if the first user cannot get the first modulo 3,
them try, bercause 2x+1, so it would need only to, the player who starts even
looses.

if Vanya starts even them she only wants to add 1, check if divisible by 3 if
add +1

if Vanya starts odd, them it already looses

but it starts at 3

*/
void solve() {
  ll t;
  cin >> t;

  if (t % 3)
    cout << "First" << endl;  // Vanya
  else
    cout << "Second" << endl;  // Vova
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

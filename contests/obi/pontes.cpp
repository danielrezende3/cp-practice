#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vld vector<ld>
#define pl pair<ll, ll>
#define vpl vector<pl>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  vector<vpl> g(n + 2);
  for (ll i = 0; i < m; i++) {
    ll s, t, b;
    cin >> s >> t >> b;
    g[s].push_back({t, b});
    g[t].push_back({s, b});
  }

  vll bs(n + 2, LLONG_MAX);
  bs[0] = 0;

  priority_queue<pl, vpl, greater<pl>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [b, s] = pq.top();
    pq.pop();

    if (b > bs[s]) {
      continue;
    }

    for (auto [nei, local_b] : g[s]) {
      ll new_b = b + local_b;

      if (new_b < bs[nei]) {
        bs[nei] = new_b;
        pq.push({new_b, nei});
      }
    }
  }
  cout << bs[n + 1] << '\n';
}
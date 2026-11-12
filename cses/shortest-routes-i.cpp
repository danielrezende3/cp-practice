#include "bits/stdc++.h"  // IWYU pragma: keep

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;

  vector<vpl> g(n + 1);

  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }

  vll dist(n + 1, LLONG_MAX);
  dist[1] = 0;

  priority_queue<pl, vpl, greater<pl>> pq;

  pq.push({0, 1});

  while (!pq.empty()) {
    auto [c, a] = pq.top();
    pq.pop();

    if (c > dist[a]) {
      continue;
    }

    for (auto [b, local_c] : g[a]) {
      ll new_c = local_c + c;

      if (new_c < dist[b]) {
        dist[b] = new_c;
        pq.push({new_c, b});
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  cout << '\n';
}
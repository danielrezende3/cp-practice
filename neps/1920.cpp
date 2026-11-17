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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x;
  cin >> x;
  vector<pair<string, string>> same(x);
  for (ll i = 0; i < x; i++) {
    cin >> same[i].first >> same[i].second;
  }

  ll y;
  cin >> y;
  vector<pair<string, string>> diff(y);
  for (ll i = 0; i < y; i++) {
    cin >> diff[i].first >> diff[i].second;
  }

  ll g;
  cin >> g;
  unordered_map<string, ll> mp;
  for (ll i = 0; i < g; i++) {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    mp[s1] = i;
    mp[s2] = i;
    mp[s3] = i;
  }

  ll ans = 0;
  for (const auto& [s1, s2] : same) {
    if (mp[s1] != mp[s2]) {
      ans++;
    }
  }

  for (const auto& [s1, s2] : diff) {
    if (mp[s1] == mp[s2]) {
      ans++;
    }
  }

  cout << ans << endl;
}
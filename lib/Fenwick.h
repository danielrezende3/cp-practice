class FenwickTree {
 private:
  vll tree;

 public:
  FenwickTree(ll n) { tree.assign(n + 1, 0); }

  void add(ll idx, ll val) {
    while (idx < tree.size()) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  }

  ll prefixSum(ll idx) {
    ll sum = 0;

    while (idx > 0) {
      sum += tree[idx];
      idx -= idx & -idx;
    }

    return sum;
  }
  
  ll rangeSum(ll l, ll r) { return prefixSum(r) - prefixSum(l - 1); }
};
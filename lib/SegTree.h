class SegmentTree {
 private:
  vll tree;

  ll merge(ll left, ll right) { return left + right; }

  ll neutral() { return 0; }

  int getN() { return tree.size() / 4; }

  void build(const vll& values, int node, int l, int r) {
    if (l == r) {
      tree[node] = values[l];
      return;
    }

    int middle = (l + r) / 2;

    build(values, node * 2, l, middle);
    build(values, node * 2 + 1, middle + 1, r);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(int node, int l, int r, int index, ll newValue) {
    if (l == r) {
      tree[node] = newValue;
      return;
    }

    int middle = (l + r) / 2;

    if (index <= middle) {
      update(node * 2, l, middle, index, newValue);
    } else {
      update(node * 2 + 1, middle + 1, r, index, newValue);
    }

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  ll query(int node, int l, int r, int queryLeft, int queryRight) {
    // Completely outside
    if (r < queryLeft || l > queryRight) {
      return neutral();
    }

    // Completely inside
    if (queryLeft <= l && r <= queryRight) {
      return tree[node];
    }

    int middle = (l + r) / 2;

    ll leftResult = query(node * 2, l, middle, queryLeft, queryRight);

    ll rightResult = query(node * 2 + 1, middle + 1, r, queryLeft, queryRight);

    return merge(leftResult, rightResult);
  }

 public:
  SegmentTree(const vll& values) {
    int n = values.size() - 1;

    tree.resize(4 * n);

    build(values, 1, 1, n);
  }

  void update(int index, ll newValue) { update(1, 1, getN(), index, newValue); }

  ll query(int l, int r) { return query(1, 1, getN(), l, r); }
};
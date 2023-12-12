#ifndef SEGTREE_HPP
#define SEGTREE_HPP
#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
public:
  SegmentTree(size_t size)
      : n(size)
  {
    Build(vector<int>(size, 0));
  }

  SegmentTree(const vector<int>& v)
      : n(v.size())
  {
    Build(v);
  }

  SegmentTree(int arr[], size_t size)
      : n(size)
  {
    Build(vector<int>(arr, arr + n));
  }

  long long query(int l, int r)
  {
    return queryUtil(root, 0, n - 1, l, r).sum;
  }

private:
  struct Node
  {
    long long sum;
    Node()
        : sum(0)
    {
    }
    explicit Node(int val)
        : sum(val)
    {
    }
  };

  size_t n;
  const int root = 1;
  const Node NONE{};
  vector<Node> tree;

  Node combine(const Node& a, const Node& b)
  {
    Node result;
    result.sum = a.sum + b.sum;
    return result;
  }

  void Build(const vector<int>& v)
  {
    while (__builtin_popcount(n) != 1)
      n++;
    tree.assign(2 * n, NONE);
    for (int i = 0; i < (int)v.size(); i++)
      tree[n + i] = Node{v[i]};
    for (int i = n - 1; i >= 1; i--)
      tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
  }

  Node queryUtil(int node, int low, int high, int l, int r)
  {
    // if node_range in inclusive in query_range
    if (l <= low && high <= r)
      return tree[node];
    // if node_range is disjoint with query_range
    if (high < l || r < low)
      return NONE;
    // ask from both left and right childs
    int mid = low + (high - low) / 2;
    return combine(queryUtil(2 * node, low, mid, l, r), queryUtil(2 * node + 1, mid + 1, high, l, r));
  }
};
#endif

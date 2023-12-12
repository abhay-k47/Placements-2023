#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).end(), (a).begin()
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vstr;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double PI = acos(-1);

// s.find_by_order(i) = i-th element in the set (0-indexing)
// s.order_of_key(elem) = #items: {item<elem}
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
template <typename S, typename T>
istream& operator>>(istream& in, pair<S, T>& p)
{
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v)
{
  for (int i = 0; i < v.size(); i++)
    in >> v[i];
  return in;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p)
{
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  for (int i = 0; i < v.size(); i++)
    out << v[i] << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, stack<T>& st)
{
  stack<T> temp;
  while (!st.empty())
  {
    out << st.top() << endl;
    temp.push(st.top());
    st.pop();
  }
  while (!temp.empty())
  {
    st.push(temp.top());
    temp.pop();
  }
  return out;
}

class SegmentTree
{
public:
  SegmentTree(const vi& v)
      : n(v.size())
  {
    Build(v);
  }

  ll query(int l, int r)
  {
    return queryUtil(root, 0, n - 1, l, r).sum;
  }
  void update(int idx, int x)
  {
    tree[n + idx].sum = x;
    for (int i = (n + idx) / 2; i >= 1; i /= 2)
      tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
  }

private:
  struct Node
  {
    ll sum;
    explicit Node(int val = 0)
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

  void Build(const vi& v)
  {
    while (__builtin_popcount(n) != 1)
      n++;
    tree.assign(2 * n, NONE);
    for (int i = 0; i < v.size(); i++)
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

void solve()
{
  const int root = 1;
  int n, q, u, v, op, s ,x;
  cin >> n >> q;
  vvi g(n + 1);
  vi val(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  for (int i = 0; i < n - 1; i++)
  {
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  function<void(int, int)> dfs;
  vi tin(n + 1), tout(n + 1), order;
  int timer = -1;
  dfs = [&](int u, int p)
  {
    order.pb(val[u]);
    tin[u] = ++timer;
    for (auto v : g[u])
      if (v != p)
        dfs(v, u);
    tout[u] = timer;
  };
  dfs(root, -1);

  SegmentTree stree(order);
  while(q--){
    cin >> op;
    if(op==1){
      cin >> s >> x;
      stree.update(tin[s], x);
    }
    else if (op==2){
      cin >> s;
      cout << stree.query(tin[s], tout[s]) << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/home/abhay/Desktop/Placements-2023/CP/input.txt", "r", stdin);
  freopen("/home/abhay/Desktop/Placements-2023/CP/output.txt", "w", stdout);
#endif
  int t = 1;
  // cin>>t;
  while (t--)
  {
    solve();
  }
#ifndef ONLINE_JUDGE
  clock_t tStart = clock();
  cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}

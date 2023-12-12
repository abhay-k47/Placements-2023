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
  SegmentTree(size_t size)
      : n(size)
  {
    Build(vi(size, 0));
  }

  SegmentTree(const vi& v)
      : n(v.size())
  {
    Build(v);
  }

  SegmentTree(int arr[], size_t size)
      : n(size)
  {
    Build(vi(arr, arr + n));
  }

  int query(int k)
  {
    return queryUtil(root, 0, n - 1, k);
  }

private:
  struct Node
  {
    int cnt;
    Node()
        : cnt(0)
    {
    }
    explicit Node(int val)
        : cnt(1)
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
    result.cnt = a.cnt + b.cnt;
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

  int queryUtil(int node, int low, int high, int k)
  {
    if (low == high)
    {
      tree[node].cnt = 0;
      for (int i = node / 2; i >= 1; i /= 2)
        tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
      return low;
    }
    int mid = low + (high - low) / 2;
    if (tree[2 * node].cnt >= k)
      return queryUtil(2 * node, low, mid, k);
    return queryUtil(2 * node + 1, mid + 1, high, k - tree[2 * node].cnt);
  }
};

void solve()
{
  int n;
  cin >> n;
  vi a(n), p(n);
  SegmentTree st(a);
  cin >> a >> p;
  for (int i = 0; i < n; i++)
    cout << a[st.query(p[i])] << " ";
  cout << endl;
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

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

  SegmentTree(int arr[], int size)
      : n(size)
  {
    Build(vi(arr, arr + n));
  }

  ll query(int l, int r)
  {
    return f(root, 0, n - 1, l, r).Xor;
  }

private:
  struct Node
  {
    ll Xor;
    Node()
        : Xor(0)
    {
    }
    Node(int val)
        : Xor(val)
    {
    }
  };

  int n;
  const int root = 1;
  const Node NONE{};
  vector<Node> tree;

  Node combine(const Node& a, const Node& b)
  {
    Node result;
    result.Xor = a.Xor ^ b.Xor;
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

  Node f(int node, int low, int high, int l, int r)
  {
    if (l <= low && high <= r)
      return tree[node];
    if (high < l || r < low)
      return NONE;
    int mid = low + (high - low) / 2;
    return combine(f(2 * node, low, mid, l, r), f(2 * node + 1, mid + 1, high, l, r));
  }
};

void solve()
{
  int n, q, l, r;
  cin >> n >> q;
  vi v(n);
  cin >> v;
  SegmentTree stree(v);
  while (q--)
  {
    cin >> l >> r;
    cout << stree.query(l - 1, r - 1) << endl;
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
//   cin >> t;
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

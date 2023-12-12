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

void solve2()
{
  const int root = 1;
  int n, q, a, b;
  cin >> n >> q;
  vi p(n + 1);
  vvi g(n + 1);
  p[root] = root;
  for (int u = 2; u <= n; u++)
  {
    cin >> p[u];
    g[u].pb(p[u]);
    g[p[u]].pb(u);
  }

  vvi ancestor(32, vi(n + 1));
  for (int i = 0; i < 32; i++)
    for (int u = 1; u <= n; u++)
      ancestor[i][u] = i ? ancestor[i - 1][ancestor[i - 1][u]] : p[u];

  function<void(int)> dfs;
  vi tin(n + 1), tout(n + 1);
  int t = 0;
  dfs = [&](int u)
  {
    tin[u] = ++t;
    for (auto v : g[u])
      if (v != p[u])
        dfs(v);
    tout[u] = ++t;
  };
  dfs(root);
  while (q--)
  {
    cin >> a >> b;
    if (a == b)
    {
      cout << a << "\n";
      continue;
    }
    if (tin[a] < tin[b] && tout[a] > tout[b])
    {
      cout << a << "\n";
      continue;
    }
    if (tin[b] < tin[a] && tout[b] > tout[a])
    {
      cout << b << "\n";
      continue;
    }
    for (int i = 31; i >= 0; i--)
      if (tin[ancestor[i][a]] > tin[b] || tout[ancestor[i][a]] < tout[b])
        a = ancestor[i][a];
    cout << ancestor[0][a] << "\n";
  }
}

void solve()
{
  const int root = 1;
  int n, q, a, b;
  cin >> n >> q;
  vvi g(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }

  function<void(int, int)> dfs;
  vi p(n + 1);
  vi d(n + 1);
  dfs = [&](int u, int par)
  {
    p[u] = par;
    if (u == root)
      d[u] = 0;
    for (auto v : g[u])
      if (v != p[u])
      {
        d[v] = d[u] + 1;
        dfs(v, u);
      }
  };
  dfs(root, root);

  vvi ancestor(32, vi(n + 1));
  for (int i = 0; i < 32; i++)
    for (int u = 1; u <= n; u++)
      ancestor[i][u] = i ? ancestor[i - 1][ancestor[i - 1][u]] : p[u];

  auto lca = [&](int a, int b)
  {
    if (d[a] > d[b])
      swap(a, b);
    int k = d[b] - d[a];
    for (int i = 31; i >= 0; i--)
      if (k & (1 << i))
        b = ancestor[i][b];
    if (a == b)
      return a;
    for (int i = 31; i >= 0; i--)
      if (ancestor[i][a] != ancestor[i][b])
        a = ancestor[i][a], b = ancestor[i][b];
    return ancestor[0][a];
  };

  while (q--)
  {
    cin >> a >> b;
    cout << d[a] + d[b] - 2 * d[lca(a, b)] << endl;
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

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

struct Edge
{
  int u;
  int v;
  int w;
};

// void solve()
// {
//   int n, m;
//   cin >> n >> m;
//   vector<Edge> edges(m);
//   for (int i = 0; i < m; i++)
//     cin >> edges[i].u >> edges[i].v >> edges[i].w;
//   vl dist(n + 1, INF);
//   vl p(n + 1, 0);
//   auto check = [&](int start)
//   {
//     dist[start] = 0;
//     p[start] = 1;
//     for (int i = 1; i < n; i++)
//     {
//       bool done = true;
//       for (auto [u, v, w] : edges)
//       {
//         if (dist[u] != INF && dist[v] > dist[u] + w)
//         {
//           dist[v] = dist[u] + w, p[v] = u;
//           done = false;
//         }
//       }
//       if(done) return;
//     }
//     for (auto [u, v, w] : edges)
//       if (dist[u] != INF && dist[v] > dist[u] + w)
//       {
//         p[v] = u;
//         vector<bool> vis(n + 1, false);
//         vis[v] = true;
//         while (!vis[u])
//         {
//           vis[u] = true;
//           u = p[u];
//         }
//         vi cycle;
//         cycle.pb(u);
//         int curr = p[u];
//         while (curr != u)
//         {
//           cycle.pb(curr);
//           curr = p[curr];
//         }
//         cycle.pb(curr);
//         reverse(all(cycle));
//         cout << "YES" << endl << cycle << endl;
//         exit(0);
//       }
//   };
//   for (int i = 1; i <=n; i++) if(dist[i]==INF)
//       check(i);
//   cout << "NO" << endl;
// }

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  for (int i = 0; i < m; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  vl dist(n + 1, INF);
  vl p(n + 1, 0);
  dist[1] = 0;
  p[1] = 1;
  for (int i = 1; i < n; i++)
  {
    bool done = true;
    for (auto [u, v, w] : edges)
    {
      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w, p[v] = u;
        done = false;
      }
    }
    if (done)
      break;
  }
  for (auto [u, v, w] : edges)
    if (dist[v] > dist[u] + w)
    {
      vector<bool> vis(n + 1, false);
      vis[v] = true;
      p[v] = u;
      while (!vis[u])
      {
        vis[u] = true;
        u = p[u];
      }
      vi cycle;
      cycle.pb(u);
      int curr = p[u];
      while (curr != u)
      {
        cycle.pb(curr);
        curr = p[curr];
      }
      cycle.pb(curr);
      reverse(all(cycle));
      cout << "YES" << endl << cycle << endl;
      return;
    }
  cout << "NO" << endl;
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

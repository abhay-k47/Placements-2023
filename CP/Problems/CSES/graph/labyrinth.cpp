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
vii dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  cin >> a;
  pii src;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == 'A')
        src = {i, j};

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  auto valid = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; };
  queue<pii> q;
  vector<vector<pii>> p(n, vector<pii>(m));
  q.push(src);
  p[src.first][src.second] = src;
  vis[src.first][src.second] = true;
  int dist = 0;
  while (!q.empty())
  {
    int sz = q.size();
    while (sz--)
    {
      auto [r, c] = q.front();
      q.pop();
      if (a[r][c] == 'B')
      {
        cout << "YES" << endl;
        cout << dist << endl;
        stack<char> path;
        pii curr = {r, c};
        while (p[curr.first][curr.second] != curr)
        {
          auto [pr, pc] = p[curr.first][curr.second];
          if (pc < curr.second)
            path.push('R');
          if (pc > curr.second)
            path.push('L');
          if (pr < curr.first)
            path.push('D');
          if (pr > curr.first)
            path.push('U');
          curr = p[curr.first][curr.second];
        }
        while (!path.empty())
        {
          cout << path.top();
          path.pop();
        }
        return;
      }
      for (auto [i, j] : dir)
      {
        if (valid(r + i, c + j) && (a[r + i][c + j] == '.' || a[r + i][c + j] == 'B') && !vis[r + i][c + j])
        {
          q.push({r + i, c + j});
          vis[r + i][c + j] = true;
          p[r + i][c + j] = {r, c};
        }
      }
    }
    dist++;
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

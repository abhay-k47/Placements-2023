#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int INF = 1e18 + 5;

void precompute()
{
}
void solve()
{
  int n, M, u, v;
  cin >> n >> M;
  vector<int> g[n + 1];
  for (int i = 1; i < n; i++)
  {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int in[n + 1], out[n + 1];
  function<void(int, int)> indfs, outdfs;
  indfs = [&](int u, int p)
  {
    in[u] = 1;
    for (int v : g[u])
      if (v != p)
      {
        indfs(v, u);
        in[u] = (in[u] * (1 + in[v])) % M;
      }
  };
  outdfs = [&](int u, int p)
  {
    if (!p)
      out[u] = 1;
    int sz = (int)g[u].size();
    int pre[sz], suf[sz];
    for (int i = 0; i < sz; i++)
      pre[i] = ((i ? pre[i - 1] : 1) * (g[u][i] != p ? 1 + in[g[u][i]] : 1)) % M;
    for (int i = sz - 1; i >= 0; i--)
      suf[i] = ((i + 1 < sz ? suf[i + 1] : 1) * (g[u][i] != p ? 1 + in[g[u][i]] : 1)) % M;
    for (int i = 0; i < sz; i++)
      if (g[u][i] != p)
      {
        out[g[u][i]] = (1 + out[u] * (i ? pre[i - 1] : 1) % M * (i + 1 < sz ? suf[i + 1] : 1)) % M;
        outdfs(g[u][i], u);
      }
  };
  indfs(1, 0);
  outdfs(1, 0);
  for (int i = 1; i <= n; i++)
    cout << (in[i] * out[i]) % M << endl;
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("/home/abhay/Desktop/Placements-2023/CP/input.txt", "r", stdin);
  freopen("/home/abhay/Desktop/Placements-2023/CP/output.txt", "w", stdout);
#endif
  precompute();
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}

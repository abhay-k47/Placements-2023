#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 5;

void precompute()
{
}

void solve()
{
  int n, m, u, v;
  cin >> n >> m;
  vector<int> g[n + 1];
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    g[u].push_back(v);
  }
  vector<int> topo;
  vector<bool> vis(n + 1, false);
  function<void(int)> dfs;
  dfs = [&](int u)
  {
    vis[u] = true;
    for (int v : g[u])
      if (!vis[v])
        dfs(v);
    topo.push_back(u);
  };
  for (int u = 1; u <= n; u++)
    if (!vis[u])
      dfs(u);
  reverse(all(topo));
  int pos[n + 1];
  for (int i = 0; i<n; i++)
    pos[topo[i]] = i;
  int dp[n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    for(int v: g[topo[i]])
      dp[pos[v]] = max(dp[pos[v]], dp[i] + 1);
  cout << *max_element(dp, dp+n) << endl;
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

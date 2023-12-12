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
  int n, u, v;
  cin >> n;
  vector<int> g[n + 1];
  for (int i = 1; i < n; i++)
  {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int dp[n + 1][2];
  function<void(int, int)> dfs;
  dfs = [&](int u, int p)
  {
    dp[u][0] = dp[u][1] = 1;
    for (int v : g[u])
    {
      if (v != p)
      {
        dfs(v, u);
        (dp[u][0] *= (dp[v][0] + dp[v][1])) %= MOD;
        (dp[u][1] *= dp[v][0]) %= MOD;
      }
    }
  };
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][1]) % MOD << endl;
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

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
  int n;
  cin >> n;
  int a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  int dp[n+1][(1 << n)];
  dp[1][0] = 0;
  for (int mask = 1; mask < (1 << n); mask++)
  {
    int submask = mask & (mask - 1);
    dp[1][mask] = dp[1][submask];
    int i = (int)log2(mask ^ submask);
    for (int j = i + 1; j < n; j++)
      if (submask & (1 << j))
        dp[1][mask] += a[i][j];
  }
  for (int i = 2; i <= n; i++)
  {
    for (int mask = 0; mask < (1 << n); mask++)
    {
      dp[i][mask] = dp[i - 1][mask];
      for (int submask = mask; submask; submask = (submask - 1) & mask)
        dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ submask] + dp[1][submask]);
    }
  }
  cout << dp[n][(1 << n) - 1] << endl;
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

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
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i)
      a[i] += a[i - 1];
  }
  int dp[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = INF;
  for (int i = 0; i < n; i++)
    dp[i][i] = 0;
  for (int len = 2; len <= n; len++)
    for (int i = 0, j = len - 1; j < n; i++, j++)
      for (int k = i; k < j; k++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - (i ? a[i - 1] : 0));
  cout << dp[0][n - 1] << endl;
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

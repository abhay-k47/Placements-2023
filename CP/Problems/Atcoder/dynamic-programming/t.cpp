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
  string s;
  cin >> s;
  int dp[n][n + 1];
  memset(dp, 0, sizeof(dp));
  for (int j = 1; j <= n; j++)
    dp[0][j] = dp[0][j - 1] + (j == 1 ? 1 : 0);
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n; j++)
    {
      (dp[i][j] += dp[i][j - 1]) %= MOD;
      if (j <= i + 1)
      {
        if (s[i - 1] == '>')
          (dp[i][j] += (dp[i - 1][n] - dp[i - 1][j - 1] + MOD)) %= MOD;
        else
          (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
      }
    }
  cout << dp[n - 1][n] << endl;
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

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
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int dp[2][k + 1];
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j <= k; j++)
    dp[0][j] = ((j ? dp[0][j - 1] : 0) + (j <= a[0] ? 1 : 0)) % MOD;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= k; j++)
      dp[i&1][j] = ((j ? dp[i&1][j - 1] : 0) + (dp[(i - 1)&1][j] - (j > a[i] ? dp[(i - 1)&1][j - a[i] - 1] : 0) + MOD) % MOD) % MOD;
  cout << (dp[(n - 1)&1][k] - (k ? dp[(n - 1)&1][k - 1] : 0) + MOD) % MOD << endl;
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

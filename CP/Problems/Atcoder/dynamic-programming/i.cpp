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
  double p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i];
  double dp[2][n + 1];
  dp[0][0] = 1.0 - p[0];
  dp[0][1] = p[0];
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= i + 1; j++)
      dp[i&1][j] = (j <= i ? dp[(i - 1)&1][j] * (1.0 - p[i]) : 0.0) + (j ? dp[(i - 1)&1][j - 1] * p[i] : 0.0);
  double ans = 0.0;
  for (int j = 0; j <= n; j++)
    if (j > n - j)
      ans += dp[(n - 1)&1][j];
  cout << setprecision(10) << ans << endl;
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

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
  int n, temp0, temp1;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int dp[2][n];
  for (int i = 0; i < n; i++)
    dp[0][i] = a[i], dp[1][i] = -a[i];
  for (int len = 2; len <= n; len++)
    for (int i = 0; i + len - 1 < n; i++)
      temp0 = max(a[i] + dp[1][i + 1], a[i + len - 1] + dp[1][i]),
      temp1 = min(-a[i] + dp[0][i + 1], -a[i + len - 1] + dp[0][i]), dp[0][i] = temp0, dp[1][i] = temp1;
  cout << dp[0][0] << endl;
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

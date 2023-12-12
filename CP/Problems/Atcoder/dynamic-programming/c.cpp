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
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];
  int dp[n][3];
  dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
  for (int i = 1; i < n; i++)
  {
    dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = b[i] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
  }
  cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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

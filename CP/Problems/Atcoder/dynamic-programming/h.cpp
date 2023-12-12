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
  int H, W;
  cin >> H >> W;
  string a[H];
  for (int i = 0; i < H; i++)
    cin >> a[i];
  int dp[2][W];
  dp[0][0] = 1;
  for (int j = 1; j < W; j++)
    dp[0][j] = (a[0][j] == '.') ? dp[0][j - 1] : 0;
  for (int i = 1; i < H; i++)
    for (int j = 0; j < W; j++)
      dp[i & 1][j] = (a[i][j] == '.') ? ((j ? dp[i & 1][j - 1] : 0) + dp[(i - 1) & 1][j]) % MOD : 0;
  cout << dp[(H - 1) & 1][W - 1] << endl;
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

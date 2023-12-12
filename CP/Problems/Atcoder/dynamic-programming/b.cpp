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
  int h[n];
  for (int i = 0; i < n; i++)
    cin >> h[i];
  int dp[n];
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    dp[i] = INF;
    for (int j = i - 1; j >= 0 && j >= i - k; j--)
      dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
  }
  cout << dp[n - 1] << endl;
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

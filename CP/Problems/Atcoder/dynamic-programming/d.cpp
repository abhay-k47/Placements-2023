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
  int n, W;
  cin >> n >> W;
  int w[n], v[n];
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  int dp[W + 1];
  for (int j = W; j >= 0; j--)
    dp[j] = -INF;
  dp[0] = 0;
  dp[w[0]] = v[0];
  for (int i = 1; i < n; i++)
    for (int j = W; j >= 0; j--)
      if (j >= w[i] && dp[j - w[i]] != INF)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  cout << *max_element(dp, dp + W + 1) << endl;
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

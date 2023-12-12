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
  bool dp[2][k + 1];
  memset(dp[0], 0, sizeof(dp[0]));
  memset(dp[1], 1, sizeof(dp[1]));
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < n && a[j] <= i; j++)
      dp[0][i] |= dp[1][i - a[j]], dp[1][i] &= dp[0][i - a[j]];
  if (dp[0][k])
    cout << "First" << endl;
  else
    cout << "Second" << endl;
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

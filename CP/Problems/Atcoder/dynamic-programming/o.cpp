#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 5;

void precompute()
{
}

int n;
int comp[21][21];
int dp[(1 << 21)];
int rec(int man, int mask)
{
  if (mask == (1 << n) - 1)
    return 1;
  int& ans = dp[mask];
  if (ans == -1)
  {
    ans = 0;
    for (int woman = 0; woman < n; woman++)
      if (comp[man][woman] && ((mask & (1 << woman)) == 0))
        ans = (ans + rec(man + 1, mask | (1 << woman))) % MOD;
  }
  return ans;
}
void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> comp[i][j];
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
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

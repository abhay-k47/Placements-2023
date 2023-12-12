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
  string s, t;
  cin >> s >> t;
  int m = (int)s.length(), n = (int)t.length();
  int dp[m][n];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (s[i] == t[j])
        dp[i][j] = 1 + ((i && j) ? dp[i - 1][j - 1] : 0);
      else
        dp[i][j] = max((i ? dp[i - 1][j] : 0), (j ? dp[i][j - 1] : 0));
  string lcs;
  int i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0)
  {
    if (s[i] == t[j])
      lcs.push_back(s[i]), i--, j--;
    else if (i && dp[i][j] == dp[i - 1][j])
      i--;
    else
      j--;
  }
  reverse(all(lcs));
  cout << lcs << endl;
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

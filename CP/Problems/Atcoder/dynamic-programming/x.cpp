#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 5;
const double PI = acos(-1);

int dp[1005][10005];
void solve()
{
  int n;
  cin >> n;
  // {s w v}
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++)
    cin >> a[i][2] >> a[i][0] >> a[i][2];
  sort(all(a));
  for (int i = 0; i<)
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
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  return 0;
}

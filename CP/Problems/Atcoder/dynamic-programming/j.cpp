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
double dp[305][305][305];
double rec(int cnt1, int cnt2, int cnt3)
{
  if (cnt1 < 0 || cnt2 < 0 || cnt3 < 0 || cnt1 + cnt2 + cnt3 == 0)
    return 0;
  if (dp[cnt1][cnt2][cnt3] < 0)
    dp[cnt1][cnt2][cnt3] = (n + cnt1 * rec(cnt1 - 1, cnt2, cnt3) + cnt2 * rec(cnt1 + 1, cnt2 - 1, cnt3) +
                            cnt3 * rec(cnt1, cnt2 + 1, cnt3 - 1)) /
                           (cnt1 + cnt2 + cnt3);
  return dp[cnt1][cnt2][cnt3];
}
void solve()
{
  cin >> n;
  int a[n], cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 1)
      cnt1++;
    else if (a[i] == 2)
      cnt2++;
    else if (a[i] == 3)
      cnt3++;
  }
  for (int i = 0; i < 305; i++)
    for (int j = 0; j < 305; j++)
      for (int k = 0; k < 305; k++)
        dp[i][j][k] = -1.0;
  cout << setprecision(18) << rec(cnt1, cnt2, cnt3) << endl;
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

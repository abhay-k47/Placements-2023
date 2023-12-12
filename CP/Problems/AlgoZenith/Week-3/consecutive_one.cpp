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
  int l = 0, r = -1;
  int cnt0 = 0;
  int ans = 0;
  while (l < n)
  {
    while (r + 1 < n && cnt0 + (1 - a[r + 1]) <= k)
    {
      cnt0 += (1 - a[r + 1]);
      r++;
    }
    ans = max(ans, r - l + 1);
    if (l <= r)
    {
      cnt0 -= (1 - a[l]);
      l++;
    }
    else
    {
      l++;
      r = l - 1;
    }
  }
  cout << ans << endl;
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
  cin >> t;
  while (t--)
    solve();
  return 0;
}

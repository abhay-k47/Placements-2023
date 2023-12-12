#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 5;

void precompute()
{
}

int d, len;
string a;
int dp[10010][2][100];
int rec(int idx, int hi, int mod)
{
  if (idx == len)
    return mod == 0;
  int& ans = dp[idx][hi][mod];
  if (ans == -1)
  {
    ans = 0;
    int l = 0, r = 9;
    if (hi)
      r = a[idx] - '0';
    for (int i = l; i <= r; i++)
    {
      int nhi = hi, nmod = (mod + i) % d;
      if (i < r)
        nhi = 0;
      (ans += rec(idx + 1, nhi, nmod)) %= MOD;
    }
  }
  return ans;
}
void solve()
{
  cin >> a >> d;
  len = (int)a.size();
  memset(dp, -1, sizeof(dp));
  cout << (rec(0, 1, 0) - 1 + MOD) % MOD << endl;
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

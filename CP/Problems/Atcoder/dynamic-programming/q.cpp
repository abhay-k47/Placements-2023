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
int sz;
int tree[1000000];
int query(int node, int low, int high, int l, int r)
{
  if (l <= low && high <= r)
    return tree[node];
  if (high < l || r < low)
    return -INF;
  int mid = low + (high - low) / 2;
  return max(query(2 * node, low, mid, l, r), query(2 * node + 1, mid + 1, high, l, r));
}

void update(int idx, int value)
{
  tree[sz + idx] = value;
  for (int i = (sz + idx) / 2; i >= 1; i /= 2)
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

void solve()
{
  cin >> n;
  int h[n], a[n];
  for (int i = 0; i < n; i++)
    cin >> h[i];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sz = n + 1;
  while (sz & (sz - 1))
    sz++;
  memset(tree, 0, sizeof(tree));
  int dp[n];
  for (int i = 0; i < n; i++)
  {
    dp[i] = a[i] + (h[i] > 1 ? query(1, 0, sz - 1, 1, h[i] - 1) : 0);
    update(h[i], dp[i]);
  }
  cout << *max_element(dp, dp + n) << endl;
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

#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 5;
typedef vector<int> Row;
typedef vector<Row> Matrix;
void precompute()
{
}

void multi(Matrix& a, Matrix& b)
{
  int n = (int)a.size();
  Matrix res(n, Row(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        (res[i][j] += a[i][k] * b[k][j]) %= MOD;
  a = res;
}

void expo(Matrix& a, int p)
{
  int n = (int)a.size();
  Matrix res(n, Row(n, 0));
  for (int i = 0; i < n; i++)
    res[i][i] = 1;
  while (p)
  {
    if (p & 1)
      multi(res, a);
    multi(a, a);
    p >>= 1;
  }
  a = res;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  Matrix adj(n, Row(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];
  expo(adj, k);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      (ans += adj[i][j]) %= MOD;
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
  // cin >> t;
  while (t--)
    solve();
  return 0;
}

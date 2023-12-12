#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).end(), (a).begin()
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vstr;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double PI = acos(-1);

// s.find_by_order(i) = i-th element in the set (0-indexing)
// s.order_of_key(elem) = #items: {item<elem}
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
template <typename S, typename T>
istream& operator>>(istream& in, pair<S, T>& p)
{
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v)
{
  for (int i = 0; i < (int)v.size(); i++)
    in >> v[i];
  return in;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p)
{
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  for (int i = 0; i < (int)v.size(); i++)
    out << v[i] << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, stack<T>& st)
{
  stack<T> temp;
  while (!st.empty())
  {
    out << st.top() << endl;
    temp.push(st.top());
    st.pop();
  }
  while (!temp.empty())
  {
    st.push(temp.top());
    temp.pop();
  }
  return out;
}

ll brute(int l, ll r)
{
  ll cnt = 0;
  for (ll i = l; i <= r; i++)
  {
    ll copy = i;
    while (copy)
    {
      int rem = copy % 10;
      if (rem % 2 == 0 || rem == 1 || i % rem == 0)
        break;
      copy /= 10;
    }
    if (copy == 0)
      cnt++;
  }
  return cnt;
}

string a, b;
ll len;
ll dp[20][2][2][2][2][2][7][2][9][2];

ll rec(int idx, int lo, int hi, int is3, int last05, int is5, int mod7, int is7, int mod9, int is9, int iszero)
{
  if (idx == len)
  {
    if ((is3 && mod9 % 3 == 0) || (is5 && last05) || (is7 && mod7 == 0) || (is9 && mod9 == 0))
      return 0;
    else
      return 1;
  }

  ll& ans = dp[idx][lo][hi][is3][last05][is5][mod7][is7][mod9][is9];
  if (ans == -1)
  {
    ans = 0;
    int l = 0, r = 9;
    if (lo)
      l = a[idx] - '0';
    if (hi)
      r = b[idx] - '0';
    for (int i = l; i <= r; i++)
    {
      if ((i == 0 && !iszero) || i == 1 || (i > 0 && i % 2 == 0))
        continue;
      int nlo = lo, nhi = hi, nis3 = is3, nis5 = is5, nis7 = is7, nis9 = is9, niszero = iszero;
      if (i > l)
        nlo = 0;
      if (i < r)
        nhi = 0;
      if (i == 3)
        nis3 = 1;
      if (i == 5)
        nis5 = 1;
      if (i == 7)
        nis7 = 1;
      if (i == 9)
        nis9 = 1;
      if (iszero && i > 0)
        niszero = 0;
      ans +=
          rec(idx + 1, nlo, nhi, nis3, i % 5 == 0, nis5, (10 * mod7 + i) % 7, nis7, (10 * mod9 + i) % 9, nis9, niszero);
    }
  }
  return ans;
}

void solve()
{
  ll l, r, k;
  cin >> l >> r >> k;
  ll ans = -1;
  while (l <= r)
  {
    ll mid = l + (r - l) / 2;
    b = to_string(mid), len = b.length();
    a = string(len - to_string(l).length(), '0') + to_string(l);
    memset(dp, -1, sizeof(dp));
    if (rec(0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1) >= k)
      ans = mid, r = mid - 1;
    else
      k -= rec(0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1), l = mid + 1;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/home/abhay/Desktop/Placements-2023/CP/input.txt", "r", stdin);
  freopen("/home/abhay/Desktop/Placements-2023/CP/output.txt", "w", stdout);
#endif
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
#ifndef ONLINE_JUDGE
  clock_t tStart = clock();
  cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}

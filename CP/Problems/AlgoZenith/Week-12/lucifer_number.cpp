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

set<int> primes;
string a, b;
int len;
ll dp[16][2][2][128][128];
ll rec(int idx, int lo, int hi, int esum, int osum)
{
  if (idx == len)
  {
    if (esum - osum > 0 && primes.count(esum - osum))
      return 1;
    else
      return 0;
  }
  ll& ans = dp[idx][lo][hi][esum][osum];
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
      int nlo = lo, nhi = hi, nesum = esum, nosum = osum;
      if (i > l)
        nlo = 0;
      if (i < r)
        nhi = 0;
      if ((len - idx) % 2 == 1)
        nosum += i;
      else
        nesum += i;
      (ans += rec(idx + 1, nlo, nhi, nesum, nosum)) %= MOD;
    }
  }
  return ans;
}

void solve()
{
  cin >> a >> b;
  len = b.size();
  a = string(len - a.size(), '0') + a;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 1, 1, 0, 0) << endl;
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

  vector<bool> isPrime(256, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < 256; i++)
    if (isPrime[i])
      for (int j = i * i; j < 256; j += i)
        isPrime[j] = false;
  for (int i = 0; i < 256; i++)
    if (isPrime[i])
      primes.insert(i);

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

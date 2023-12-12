#include "sparse_table.hpp"
#include "trie.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/home/abhay/Desktop/Placements-2023/CP/input.txt", "r", stdin);
  freopen("/home/abhay/Desktop/Placements-2023/CP/output.txt", "w", stdout);
  clock_t tStart = clock();
#endif

  // Trie t;
  // t.insert("abracadabra");
  // t.insert("ababa");
  // t.insert("abcd");
  // t.insert("hello");
  // cout << t.search("abcd") << endl;
  // cout << t.search("abc") << endl;
  // cout << t.search("world") << endl;
  // cout << t.prefix_search("") << endl;
  // cout << t.prefix_search("ab") << endl;
  // cout << t.prefix_search("abcd") << endl;
  // cout << t.prefix_search("help") << endl;
  vector<int> v = {1, 15, 3, 10, 3, 2, 17, 4, 6, -3, 5, 1};
  SparseTable<int> st(v);
  for (int i = 0; i < 12; i++)
    for (int j = i; j < 12; j++)
      cout << i << " " << j << " " << st.query(i, j) << endl;
#ifndef ONLINE_JUDGE
  cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief KMP Algorithm
 * @details Main idea: find the longest proper suffix that is also a prefix of s[0..i]
 *
 */

vector<int> prefix_function(string s)
{
  int n = (int)s.length();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++)
  {
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j])
      j = lps[j - 1];
    if (s[i] == s[j])
      j++;
    lps[i] = j;
  }
  return lps;
}

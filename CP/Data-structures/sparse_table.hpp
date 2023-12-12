/**
 * @file sparse_table.hpp
 * @author Abhay Keshari (akabhay9585@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SPARSE_TABLE_HPP
#define SPARSE_TABLE_HPP
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief O(1) range query (no updates) for any idempotent function e.g. min, max, gcd, AND, OR
 *
 * @tparam T
 */
template <class T>
class SparseTable
{
public:
  SparseTable(const vector<T>& v)
      : n(v.size())
      , log2(vector<int>(n + 1))
      , st(vector<vector<T>>(n))
  {
    log2[0] = INT_MIN;
    log2[1] = 0;
    for (int i = 2; i <= n; i++)
      log2[i] = log2[i / 2] + 1;
    for (int i = 0; i < n; i++)
      st[i].resize(log2[n]);
    for (int j = 0; j <= log2[n]; j++)
    {
      for (int i = 0; i + (1 << j) - 1 < n; i++)
      {
        st[i][j] = j ? min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]) : v[i];
      }
    }
  }
  SparseTable(T v[], int size)
      : n(size)
      , log2(vector<int>(n + 1))
      , st(vector<vector<T>>(n))
  {
    log2[0] = INT_MIN;
    log2[1] = 0;
    for (int i = 2; i <= n; i++)
      log2[i] = log2[i / 2] + 1;
    for (int i = 0; i < n; i++)
      st[i].resize(log2[n]);
    for (int j = 0; j <= log2[n]; j++)
    {
      for (int i = 0; i + (1 << j) - 1 < n; i++)
      {
        st[i][j] = j ? min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]) : v[i];
      }
    }
  }

  T query(int l, int r)
  {
    int j = log2[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
  }

  ~SparseTable() = default;

private:
  int n;
  vector<int> log2;
  vector<vector<T>> st;
};
#endif

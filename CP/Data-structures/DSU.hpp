/**
 * @file DSU.hpp
 * @author Abhay Keshari (akabhay9585@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>

class DSU
{
  explicit DSU(std::size_t n)
      : size(n)
      , parent(std::vector<int>(n + 1))
      , rank(std::vector<int>(n + 1))
      , count(std::vector<int>(n + 1))
  {
    build();
  }
  void build()
  {
    for (int i = 1; i <= size; i++)
      parent[i] = i, rank[i] = 0, count[i] = 1;
  }

  int find(int u)
  {
    if (parent[u] == u)
      return parent[u];
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v)
  {
    u = find(u), v = find(v);
    if (u != v)
    {
      if (rank[u] > rank[v])
        std::swap(u, v);
      parent[u] = v;
      count[v] += count[u];
      if (rank[u] == rank[v])
        rank[v]++;
    }
  }

private:
  std::size_t size;
  std::vector<int> parent;
  std::vector<int> rank;
  std::vector<int> count;
};

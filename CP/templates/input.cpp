#include <bits/stdc++.h>

template <typename S, typename T>
std::istream& operator>>(std::istream& in, std::pair<S, T>& p)
{
  in >> p.first >> p.second;
  return in;
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& v)
{
  for (int i = 0; i < (int)v.size(); i++)
    in >> v[i];
  return in;
}

template <typename T>
void input(T arr[], size_t size, std::istream& in = std::cin)
{
  for (size_t i = 0; i < size; i++)
    in >> arr[i];
}

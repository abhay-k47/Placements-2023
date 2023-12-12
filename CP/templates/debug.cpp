#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(...)                          \
  std::cerr << "Line#" << __LINE__ << ": "; \
  err(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) \
  {                \
  }
#endif

template <typename T>
void err(std::string name, T arg)
{
  std::cerr << name << " = " << arg << std::endl;
}

template <typename T1, typename... T2>
void err(std::string names, T1 arg, T2... args)
{
  std::cerr << names.substr(0, names.find(',')) << " = " << arg << " , ";
  err(names.substr(names.find(',') + 2), args...);
}

template <typename S, typename T>
std::ostream& operator<<(std::ostream& out, const std::pair<S, T>& p)
{
  out << "{" << p.first << "," << p.second << "}";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
  out << "[";
  for (auto it = v.begin(); it != v.end(); ++it)
  {
    out << *it;
    if (it != --v.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s)
{
  out << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
  {
    out << *it;
    if (it != --s.end())
      out << ", ";
  }
  out << "}";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& s)
{
  out << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
  {
    out << *it;
    if (it != --s.end())
      out << ", ";
  }
  out << "}";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& s)
{
  size_t i = 0;
  out << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
  {
    i++;
    out << *it;
    if (i != s.size())
      out << ", ";
  }
  out << "}";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& s)
{
  size_t i = 0;
  out << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
  {
    i++;
    out << *it;
    if (i != s.size())
      out << ", ";
  }
  out << "}";
  return out;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const std::map<K, V>& mp)
{
  out << "[";
  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    out << *it;
    if (it != --mp.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const std::multimap<K, V>& mp)
{
  out << "[";
  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    out << *it;
    if (it != --mp.end())
      out << ", ";
  }
  out << "]";
  return out;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<K, V>& mp)
{
  size_t i = 0;
  out << "[";
  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    i++;
    out << *it;
    if (i != mp.size())
      out << ", ";
  }
  out << "]";
  return out;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& out, const std::unordered_multimap<K, V>& mp)
{
  size_t i = 0;
  out << "[";
  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    i++;
    out << *it;
    if (i != mp.size())
      out << ", ";
  }
  out << "]";
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::stack<T>& st)
{
  std::stack<T> temp;
  std::string s = "";
  while (!st.empty())
  {
    s += to_string(st.top()) + " ";
    temp.push(st.top());
    st.pop();
  }
  s += " |";
  out << std::string(s.size(), '-') << std::endl << s << std::endl << std::string(s.size(), '-') << std::endl;
  while (!temp.empty())
  {
    st.push(temp.top());
    temp.pop();
  }
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::queue<T>& q)
{
  size_t i = 0;
  std::string s = "";
  while (i < q.size())
  {
    i++;
    s += to_string(q.front()) + " ";
    q.push(q.front());
    q.pop();
  }
  out << "   " << std::string(s.size(), '-') << std::endl;
  out << "<- " + s + " <-" << std::endl;
  out << "   " << std::string(s.size(), '-') << std::endl;
  return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::priority_queue<T>& q)
{
  std::priority_queue<T> temp;
  out << "[";
  while (!q.empty())
  {
    out << q.top();
    temp.push(q.top());
    q.pop();
    if (!q.empty())
      out << ", ";
  }
  out << "]";
  while (!temp.empty())
  {
    q.push(temp.top());
    temp.pop();
  }
  return out;
}

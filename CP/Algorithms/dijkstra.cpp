#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int src)
{
  int n = graph.size() - 1;
  vector<int> p(n, -1), dist(n, __INT_MAX__);
  vector<bool> vis(n, false);
  priority_queue<pair<int, int>> pq;
  dist[src] = 0;
  p[src] = src;
  pq.push({dist[src], src});
  while (!pq.empty())
  {
    auto u = pq.top().second;
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (auto [v, w] : graph[u])
    {
      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w;
        p[v] = w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int main()
{
  int m, n, u, v, w;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n + 1);
  while (m--)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  auto dist = dijkstra(graph, 1);
  return 0;
}

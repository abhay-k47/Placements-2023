#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const size_t N = 1e5 + 10;

vector<int> graph[N];
bool visited[N];
int parent[N];

/**
 * @brief dfs traversal of a tree
 *
 * @param vertex
 */
void dfs(int vertex)
{
  // TODO: after entering the vertex
  visited[vertex] = true;

  for (int child : graph[vertex])
  {
    // TODO: before entering child node
    if (visited[child])
      continue;
    parent[child] = vertex;

    dfs(child);

    // TODO: after exiting child node
  }

  // TODO: before exiting the vertex
}

/**
 * @brief dfs traversal of a tree
 *
 * @param vertex
 * @param parent
 */
void dfs(int vertex, int parent)
{
  // TODO: after entering the vertex

  for (int child : graph[vertex])
  {
    // TODO: before entering child node
    if (child == parent)
      continue;

    dfs(child, vertex);

    // TODO: after exiting child node
  }

  // TODO: before exiting the vertex
}

/**
 * @brief computes the number of connected components in a graph
 *
 * @param V
 * @return int
 */
int connectedComponents(int V)
{
  int components = 0;
  for (int vertex = 0; vertex < V; vertex++)
  {
    if (visited[vertex])
      continue;
    dfs(vertex);
    components++;
  }
  return components;
}

/**
 * @brief utility function to check if a graph contains a cycle
 *
 * @param vertex
 * @param parent
 * @return true
 * @return false
 */
bool isCycleUtil(int vertex, int parent = -1)
{
  visited[vertex] = true;

  for (int child : graph[vertex])
  {
    if (child == parent)
      continue;
    if (visited[child])
    {
      // To print the cycle, use the parent array to backtrack from the vertex to the child
      return true;
    }

    if (isCycleUtil(child, vertex))
      return true;
  }
  return false;
}

/**
 * @brief checks if a graph contains a cycle
 *
 * @param V
 * @return true
 * @return false
 */
bool isCycle(int V)
{
  for (int vertex = 0; vertex < V; vertex++)
  {
    if (visited[vertex])
      continue;
    if (isCycleUtil(vertex))
      return true;
  }
  return false;
}

int n, L;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= L; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];

  for (int u : adj[v])
  {
    if (u != p)
      dfs(u, v);
  }

  tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = L; i >= 0; --i)
  {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

void preprocess(int root)
{
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  L = ceil(log2(n));
  up.assign(n, vector<int>(L + 1));
  dfs(root, root);
}

vector<int> toposort;
void dfs(int u)
{
  vis[u] = true;
  for (int v : g[u])
  {
    if (vis[v])
      continue;
    dfs(v, u);
  }
  toposort.push_back(u);
}

void kahnsAlgo()
{
  vector<int> indegree;
  indegree.assign(n, 0);
  for (int u = 0; u < n; u++)
    for (int v : g[u])
      indegree[v]++;

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (!indegree[i])
      q.push(i);

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    toposort.push_back(u);
    for (int v : g[u])
      if (--indegree[v] == 0)
        q.push(v);
  }

  if (toposort.size() < n)
    toposort.assign(n, -1);
}
void topological_sort()
{
  toposort.clear();
  vis.assign(n, false);
  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i);
  reverse(toposort.begin(), toposort.end());
}

/**
 * @brief Bellman–Ford algorithm: single source shortest path in a weighted directed graph but can handle graphs with
negative edge weights.
 *
 * If a graph contains a "negative cycle" (i.e. a cycle whose edges sum to a negative value) that is reachable from the
source, then there is no cheapest path: any path that has a point on the negative cycle can be made cheaper by one more
walk around the negative cycle. In such a case, the Bellman–Ford algorithm can detect and report the negative cycle.
 *
 * Lemma: After i repetitions of for loop,
    1. if Distance(u) is not infinity, it is equal to the length of some path from s to u; and
    2. if there is a path from s to u with at most i edges, then Distance(u) is at most the length of the shortest path
from s to u with at most i edges.
 *
 * Since the longest possible path without a cycle can be |V|-1 edges, the edges must be scanned |V|-1 times to ensure
the shortest path has been found for all nodes.
 *
 * A final scan of all the edges is performed and if any distance is updated, then a path of length |V| edges has been
found which can only occur if at least one negative cycle exists in the graph.
 *
 * The edge (u, v) that is found in step 3 must be reachable from a negative cycle, but it isn't necessarily part of the
cycle itself, which is why it's necessary to follow the path of predecessors backwards until a cycle is detected.
 *
 * If there are no negative-weight cycles, then every shortest path visits each vertex at most once, so at step 3 no
further improvements can be made.
 * Conversely, suppose no improvement can be made. Then for any cycle with vertices v[0],..., v[k−1],
 *    v[i].distance <= v[i-1 (mod k)].distance + v[i-1 (mod k)]v[i].weight
 * Summing around the cycle gives { 0 <= sum from 1 to k of v[i-1 (mod k)]v[i].weight } i.e., every cycle has
nonnegative weight.
 *
 * Improvements: return early when an iteration of step 2 fails to relax any edges, which implies all shortest paths
have been found, and therefore there are no negative cycles.
 * Complexity reduces from O(|V|*|E|) to O(l*|E|) where l is the maximum length of a shortest path.
 *
 */

function BellmanFord(list vertices, list edges, vertex source)

    // This implementation takes in a graph, represented as
    // lists of vertices (represented as integers [0..n-1]) and edges,
    // and fills two arrays (distance and predecessor) holding
    // the shortest path from the source to each vertex

    distance := list of size n
    predecessor := list of size n

    // Step 1: initialize graph
    for each vertex v in vertices do
        // Initialize the distance to all vertices to infinity
        distance[v] := inf
        // And having a null predecessor
        predecessor[v] := null
    
    // The distance from the source to itself is, of course, zero
    distance[source] := 0

    // Step 2: relax edges repeatedly
    repeat |V|-1 times:
        for each edge (u, v) with weight w in edges do
            if distance[u] + w < distance[v] then
                distance[v] := distance[u] + w
                predecessor[v] := u

    // Step 3: check for negative-weight cycles
    for each edge (u, v) with weight w in edges do
        if distance[u] + w < distance[v] then
            predecessor[v] := u
            // A negative cycle exist; find a vertex on the cycle 
            visited := list of size n initialized with false
            visited[v] := true
            while not visited[u] do
                visited[u] := true
                u := predecessor[u]
            // u is a vertex in a negative cycle, find the cycle itself
            ncycle := [u]
            v := predecessor[u]
            while v != u do
                ncycle := concatenate([v], ncycle)
                v := predecessor[v]
            error "Graph contains a negative-weight cycle", ncycle
    return distance, predecessor

#endif

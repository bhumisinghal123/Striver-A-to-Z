#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
  {
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
      parent[i] = i;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
      auto it = pq.top();
      int node = it.second;
      int dis = it.first;
      pq.pop();

      for (auto it : adj[node])
      {
        int adjNode = it.first;
        int edW = it.second;
        if (dis + edW < dist[adjNode])
        {
          dist[adjNode] = dis + edW;
          pq.push({dist[adjNode], adjNode});
          parent[adjNode] = node;
        }
      }
    }
    if (dist[n] == 1e9)
      return {-1};
    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
  }
};

int main()
{
  int n = 5, m = 6;

  vector<vector<int>> edges = {
      {1, 2, 2},
      {1, 4, 1},
      {4, 3, 3},
      {2, 3, 4},
      {2, 5, 5},
      {3, 5, 1}};

  Solution obj;
  vector<int> path = obj.shortestPath(n, m, edges);

  if (path.size() == 1 && path[0] == -1)
  {
    cout << "No path exists\n";
  }
  else
  {
    for (int node : path)
      cout << node << " ";
    cout << endl;
  }

  return 0;
}

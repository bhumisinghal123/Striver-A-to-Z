/*
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
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
      dist[i] = 1e9;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto it : adj[node])
      {
        int edgeWeight = it[1];
        int adjNode = it[0];

        if (dis + edgeWeight < dist[adjNode])
        {
          dist[adjNode] = dis + edgeWeight;
          pq.push({dist[adjNode], adjNode});
        }
      }
    }
    return dist;
  }
};

int main()
{
  int V = 5;
  vector<vector<int>> adj[V];

  adj[0].push_back({1, 2});
  adj[0].push_back({3, 1});
  adj[1].push_back({0, 2});
  adj[1].push_back({2, 4});
  adj[1].push_back({4, 5});
  adj[2].push_back({1, 4});
  adj[2].push_back({3, 3});
  adj[2].push_back({4, 1});
  adj[3].push_back({0, 1});
  adj[3].push_back({2, 3});
  adj[4].push_back({1, 5});
  adj[4].push_back({2, 1});

  Solution obj;
  vector<int> dist = obj.dijkstra(V, adj, 0);

  cout << "Vertex Distance from Source (0):\n";
  for (int i = 0; i < V; i++)
    cout << "Vertex " << i << ": " << dist[i] << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
      auto it = *(st.begin());
      int node = it.second;
      int dis = it.first;
      st.erase(it);

      for (auto it : adj[node])
      {
        int adjNode = it[0];
        int edgW = it[1];

        if (dis + edgW < dist[adjNode])
        {
          if (dist[adjNode] != 1e9)
            st.erase({dist[adjNode], adjNode});

          dist[adjNode] = dis + edgW;
          st.insert({dist[adjNode], adjNode});
        }
      }
    }
    return dist;
  }
};

int main()
{
  int V = 5;
  vector<vector<int>> adj[V];

  adj[0].push_back({1, 2});
  adj[0].push_back({3, 1});
  adj[1].push_back({0, 2});
  adj[1].push_back({2, 4});
  adj[1].push_back({4, 5});
  adj[2].push_back({1, 4});
  adj[2].push_back({3, 3});
  adj[2].push_back({4, 1});
  adj[3].push_back({0, 1});
  adj[3].push_back({2, 3});
  adj[4].push_back({1, 5});
  adj[4].push_back({2, 1});

  Solution obj;
  vector<int> dist = obj.dijkstra(V, adj, 0);

  cout << "Vertex Distance from Source (0):\n";
  for (int i = 0; i < V; i++)
    cout << "Vertex " << i << ": " << dist[i] << endl;

  return 0;
}

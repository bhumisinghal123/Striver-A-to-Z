#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
  bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
  {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (dfsCheck(it, adj, vis, pathVis) == true)
          return true;
      }
      else if (pathVis[it])
      {
        return true;
      }
    }
    pathVis[node] = 0;
    return false;
  }

public:
  bool isCyclic(int V, vector<int> adj[])
  {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfsCheck(i, adj, vis, pathVis) == true)
          return true;
      }
    }
    return false;
  }
};

int main()
{
  int V = 4;
  vector<int> adj[V];

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);

  Solution obj;
  bool ans = obj.isCyclic(V, adj);
  if (ans)
    cout << "Cycle detected in directed graph";
  else
    cout << "No Cycle detected in directed graph";
  return 0;
}
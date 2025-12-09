#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
  {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, adj, vis, ls);
      }
    }
  }

public:
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
  }
};

int main()
{
  int V = 5;
  vector<int> adj[V];

  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(0);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(0);
  adj[3].push_back(1);
  adj[4].push_back(1);

  Solution sol;
  vector<int> result = sol.dfsOfGraph(V, adj);

  cout << "DFS Traversal: ";
  for (int node : result)
  {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> eventualSafeNodes(int V, vector<int> adj[])
  {
    vector<int> adjRev[V];
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        adjRev[it].push_back(i);
        indegree[i]++;
      }
    }
    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      safeNodes.push_back(node);
      for (auto it : adjRev[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
  }
};

int main()
{
  int V = 7;
  vector<int> adj[V];
  adj[0] = {1, 2};
  adj[1] = {2, 3};
  adj[2] = {5};
  adj[3] = {0};
  adj[4] = {5};
  adj[5] = {};
  adj[6] = {4, 5};

  Solution sol;
  vector<int> safeNodes = sol.eventualSafeNodes(V, adj);

  cout << "Eventual Safe Nodes: ";
  for (int node : safeNodes)
  {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
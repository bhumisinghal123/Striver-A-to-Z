#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findOrder(int V, int m, vector<vector<int>> &prerequisites)
  {
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
      adj[it[1]].push_back(it[0]);
    }

    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        indegree[it]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }
    vector<int> topo;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for (auto it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }
    if (topo.size() == V)
      return topo;
    return {};
  }
};

int main()
{
  int V = 4;
  int m = 4;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  Solution obj;
  vector<int> result = obj.findOrder(V, m, prerequisites);

  if (result.empty())
  {
    cout << "No valid course order exists." << endl;
  }
  else
  {
    cout << "A valid course order is: ";
    for (int course : result)
    {
      cout << course << " ";
    }
    cout << endl;
  }

  return 0;
}
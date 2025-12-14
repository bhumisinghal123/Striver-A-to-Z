#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isCyclic(int V, vector<int> adj[])
  {
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
    int cnt = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      cnt++;

      for (auto it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
        {
          q.push(it);
        }
      }
    }
    if (cnt == V)
      return false;
    return true;
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
  bool hasCycle = obj.isCyclic(V, adj);

  if (hasCycle)
    cout << "Graph contains a cycle." << endl;
  else
    cout << "Graph does not contain a cycle." << endl;

  return 0;
}
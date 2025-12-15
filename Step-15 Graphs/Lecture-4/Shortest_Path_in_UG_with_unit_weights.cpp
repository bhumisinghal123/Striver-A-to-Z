#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
  {
    vector<int> adj[N];
    for (auto it : edges)
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }

    int dist[N];
    for (int i = 0; i < N; i++)
      dist[i] = 1e9;
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      for (auto it : adj[node])
      {
        if (dist[node] + 1 < dist[it])
        {
          dist[it] = dist[node] + 1;
          q.push(it);
        }
      }
    }
    vector<int> ans(N, -1);
    for (int i = 0; i < M; i++)
    {
      if (dist[i] != 1e9)
      {
        ans[i] = dist[i];
      }
    }
    return ans;
  }
};

int main()
{
  int N = 9, M = 10;
  vector<vector<int>> edges;
  edges.push_back({0, 1});
  edges.push_back({0, 3});
  edges.push_back({1, 2});
  edges.push_back({3, 4});
  edges.push_back({3, 7});
  edges.push_back({4, 5});
  edges.push_back({4, 6});
  edges.push_back({4, 8});
  edges.push_back({5, 6});
  edges.push_back({6, 7});
  int src = 0;

  Solution obj;
  vector<int> res = obj.shortestPath(edges, N, M, src);
  for (auto x : res)
    cout << x << " ";
  cout << endl;
  return 0;
}
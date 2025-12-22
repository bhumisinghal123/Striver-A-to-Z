#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void shortest_distance(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == -1)
        {
          matrix[i][j] = 1e9;
        }
        if (i == j)
        {
          matrix[i][j] = 0;
        }
      }
    }

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 1e9)
        {
          matrix[i][j] = -1;
        }
      }
    }
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {
      {0, 3, -1, 7},
      {8, 0, 2, -1},
      {5, -1, 0, 1},
      {2, -1, -1, 0}};

  sol.shortest_distance(matrix);

  for (const auto &row : matrix)
  {
    for (const auto &val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
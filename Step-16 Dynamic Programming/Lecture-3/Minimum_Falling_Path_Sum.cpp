/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int f(int i, int j, vector<vector<int>> &matrix)
  {
    if (j < 0 || j >= matrix[0].size())
      return -1e8;
    if (i == 0)
      return matrix[0][j];

    int u = matrix[i][j] + f(i - 1, j, matrix);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix);

    return max(u, max(ld, rd));
  }

  int getMaxPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
      maxi = max(maxi, f(n - 1, j, matrix));
    }
    return maxi;
  }
};

int main()
{
  vector<vector<int>> grid = {
      {5, 9, 6},
      {11, 5, 2}};

  Solution obj;
  cout << "Minimum sum path: "
       << obj.getMaxPathSum(grid) << endl;

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
  {
    if (j < 0 || j >= matrix[0].size())
      return -1e8;
    if (i == 0)
      return matrix[0][j];

    if(dp[i][j] != -1) return dp[i][j];

    int u = matrix[i][j] + f(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max(u, max(ld, rd));
  }

  int getMaxPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
    {
      maxi = max(maxi, f(n - 1, j, matrix, dp));
    }
    return maxi;
  }
};

int main()
{
  vector<vector<int>> grid = {
      {5, 9, 6},
      {11, 5, 2}};

  Solution obj;
  cout << "Minimum sum path: "
       << obj.getMaxPathSum(grid) << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getMaxPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m), cur(m);

    for (int j = 0; j < m; j++)
    {
      prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int up = prev[j];
        int ld = (j > 0) ? prev[j - 1] : -1e8;
        int rd = (j < m - 1) ? prev[j + 1] : -1e8;

        cur[j] = matrix[i][j] + max(up, max(ld, rd));
      }
      prev = cur;
    }

    return *max_element(prev.begin(), prev.end());
  }
};

int main()
{
  vector<vector<int>> grid = {
      {5, 9, 6},
      {11, 5, 2}};

  Solution obj;
  cout << obj.getMaxPathSum(grid) << endl;

  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          for (int col = 0; col < n; col++)
          {
            if (matrix[i][col] != 0)
              matrix[i][col] = -1;
          }
          for (int row = 0; row < m; row++)
          {
            if (matrix[row][j] != 0)
              matrix[row][j] = -1;
          }
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == -1)
          matrix[i][j] = 0;
      }
    }
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  Solution sol;
  sol.setZeroes(matrix);

  for (auto row : matrix)
  {
    for (auto val : row)
    {
      cout << val << " ";
    }
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
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (row[i] == 1 || col[j] == 1)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  Solution obj;
  obj.setZeroes(matrix);

  for (auto row : matrix)
  {
    for (auto val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
  int n = matrix.size();
  int m = matrix[0].size();
  int col0 = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 0)
      {
        // mark the i-th row
        matrix[i][0] = 0;
        // mark the j-th col
        if (j != 0)
          matrix[0][j] = 0;
        else
          col0 = 0;
      }
    }
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      if (matrix[i][j] != 0)
      {
        // check for col & row
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
  if (matrix[0][0] == 0)
  {
    for (int j = 0; j < m; j++)
      matrix[0][j] = 0;
  }
  if (col0 == 0)
  {
    for (int i = 0; i < n; i++)
    {
      matrix[i][0] = 0;
    }
  }
  return matrix;
}

int main()
{
  int n, m;
  cout << "Enter number of rows: ";
  cin >> n;
  cout << "Enter number of columns: ";
  cin >> m;

  vector<vector<int>> matrix(n, vector<int>(m));

  cout << "Enter matrix elements:\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  vector<vector<int>> result = zeroMatrix(matrix, n, m);

  cout << "\nMatrix after applying zeroMatrix:\n";
  for (const auto &row : result)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << "\n";
  }

  return 0;
}
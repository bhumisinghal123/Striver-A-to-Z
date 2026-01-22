/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    vector<vector<int>> rotated(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        rotated[j][n - i - 1] = matrix[i][j];
      }
    }

    return rotated;
  }
};

int main()
{
  vector<vector<int>> mat = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  Solution obj;
  vector<vector<int>> rotated = obj.rotateClockwise(mat);

  for (auto row : rotated)
  {
    for (int val : row)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
  int n = mat.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      swap(mat[i][j], mat[j][i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    reverse(mat[i].begin(), mat[i].end());
  }
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

  rotateMatrix(matrix);

  cout << "\nMatrix after applying zeroMatrix:\n";
  for (const auto &row : matrix)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << "\n";
  }
  return 0;
}

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

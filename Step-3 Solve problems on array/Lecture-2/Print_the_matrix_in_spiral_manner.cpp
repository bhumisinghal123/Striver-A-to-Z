#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int left = 0, right = m - 1;
  int top = 0, bottom = n - 1;
  vector<int> ans;

  while (top <= bottom && left <= right)
  {
    for (int i = left; i <= right; i++)
    {
      ans.push_back(mat[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; i++)
    {
      ans.push_back(mat[i][right]);
    }
    right--;
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        ans.push_back(mat[bottom][i]);
      }
      bottom--;
    }
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        ans.push_back(mat[i][left]);
      }
      left++;
    }
  }
  return ans;
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

  vector<int> result = spiralMatrix(matrix);
  cout << "Spiral Order: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
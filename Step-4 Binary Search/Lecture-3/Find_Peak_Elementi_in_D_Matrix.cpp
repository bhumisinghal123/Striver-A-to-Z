#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col)
{
  int maxValue = -1;
  int index = -1;
  for (int i = 0; i < n; i++)
  {
    if (mat[i][col] > maxValue)
    {
      maxValue = mat[i][col];
      index = i;
    }
  }
  return index;
}

vector<int> findPeakgrid(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int maxRowIndex = findMaxIndex(mat, n, m, mid);
    int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
    int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;
    if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
    {
      return {maxRowIndex, mid};
    }
    else if (mat[maxRowIndex][mid] < left)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return {-1, -1};
}

int main()
{
  vector<vector<int>> matrix = {{10, 8, 10, 10},
                                {14, 13, 12, 11},
                                {15, 9, 11, 21}};
  vector<int> peak = findPeakgrid(matrix);
  cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")\n";
  return 0;
}
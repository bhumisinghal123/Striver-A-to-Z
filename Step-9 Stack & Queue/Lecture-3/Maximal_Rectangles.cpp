#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    stack<int> st;
    int largestArea = 0;
    int area;
    int nse, pse;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && heights[st.top()] >= heights[i])
      {
        int ind = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();
        nse = i;
        area = heights[ind] * (nse - pse - 1);
        largestArea = max(largestArea, area);
      }
      st.push(i);
    }
    while (!st.empty())
    {
      nse = n;
      int ind = st.top();
      st.pop();
      pse = st.empty() ? -1 : st.top();
      area = heights[ind] * (nse - pse - 1);
      largestArea = max(largestArea, area);
    }
    return largestArea;
  };

public:
  int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefixSum(n, vector<int>(m));
    for (int j = 0; j < m; j++)
    {
      int sum = 0;
      for (int i = 0; i < n; i++)
      {
        sum += (matrix[i][j] - '0');
        if (matrix[i][j] == '0')
        {
          prefixSum[i][j] = 0;
          sum = 0;
        }
        prefixSum[i][j] = sum;
      }
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
      int area = largestRectangleArea(prefixSum[i]);
      maxArea = max(area, maxArea);
    }
    return maxArea;
  }
};

int main()
{
  vector<vector<int>> matrix = {
      {1, 0, 1, 0, 0},
      {1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 0, 0, 1, 0}};

  Solution sol;
  int ans = sol.maximalAreaOfSubMatrixOfAll1(matrix);
  cout << "The largest rectangle area containing all 1s is: " << ans;
  return 0;
}
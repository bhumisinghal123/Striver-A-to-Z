#include <bits/stdc++.h>
using namespace std;

/*
int nCr(int n, int r)
{
  long long res = 1;
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}
int main()
{
  int n;
  cin >> n;
  int r;
  cin >> r;
  cout << nCr(n, r);
  return 0;
}
*/

/*
void row(int n)
{
  long long ans = 1;
  cout << ans;
  for (int i = 1; i < n; i++)
  {
    ans = ans * (n - i);
    ans = ans / i;
    cout << ans;
  }
}
int main()
{
  int n;
  cin >> n;
  row(n);
  return 0;
}
*/

vector<int> generateRow(int row)
{
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(1);
  for (int col = 1; col < row; col++)
  {
    ans = ans * (row - col);
    ans = ans / (col);
    ansRow.push_back(ans);
  }
  return ansRow;
};

vector<vector<int>> pascalTriangle(int N)
{
  vector<vector<int>> ans;
  for (int i = 1; i <= N; i++)
  {
    ans.push_back(generateRow(i));
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> triangle = pascalTriangle(n);
  for (const auto &row : triangle)
  {
    for (long long val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}

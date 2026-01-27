/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; i++)
    {
      vector<int> row(i + 1, 1);

      for (int j = 1; j < i; j++)
      {
        row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }

      triangle.push_back(row);
    }
    return triangle;
  }
};

int main()
{
  Solution obj;
  int n = 5;

  vector<vector<int>> result = obj.generate(n);
  for (auto &row : result)
  {
    for (auto &val : row)
      cout << val << " ";
    cout << endl;
  }
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> getNthRow(int N)
  {
    vector<long long> row;

    long long val = 1;
    row.push_back(val);

    for (int k = 1; k < N; k++)
    {
      val = val * (N - k) / k;
      row.push_back(val);
    }

    return row;
  }
};

int main()
{
  int N = 5;
  Solution sol;
  vector<long long> result = sol.getNthRow(N);

  for (auto num : result)
  {
    cout << num << " ";
  }
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long findPascalElement(int r, int c)
  {
    int n = r - 1;
    int k = c - 1;

    long long result = 1;

    for (int i = 0; i < k; i++)
    {
      result *= (n - i);
      result /= (i + 1);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int r = 5, c = 3;
  cout << sol.findPascalElement(r, c);
  return 0;
}

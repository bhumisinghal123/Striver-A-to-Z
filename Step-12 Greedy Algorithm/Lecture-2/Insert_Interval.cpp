#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &newInterval)
{
  int n = arr.size();
  vector<vector<int>> res;
  int i = 0;
  while (i < n && arr[i][1] < newInterval[0])
  {
    res.push_back(arr[i]);
    i++;
  }
  while (i < n && arr[i][0] <= newInterval[1])
  {
    newInterval[0] = min(newInterval[0], arr[i][0]);
    newInterval[1] = max(newInterval[1], arr[i][1]);
    i++;
  }
  res.push_back(newInterval);
  while (i < n)
  {
    res.push_back(arr[i]);
    i++;
  }
  return res;
}

int main()
{
  vector<vector<int>> arr = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
  vector<int> newInterval = {4, 8};

  vector<vector<int>> result = insert(arr, newInterval);

  cout << "Result: ";
  for (auto &interval : result)
  {
    cout << "[" << interval[0] << ", " << interval[1] << "] ";
  }
  cout << endl;

  return 0;
}

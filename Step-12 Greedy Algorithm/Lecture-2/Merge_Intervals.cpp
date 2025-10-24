#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0)
    {
      return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];

    for (auto it : intervals)
    {
      if (it[0] <= tempInterval[1])
      {
        tempInterval[1] = max(it[1], tempInterval[1]);
      }
      else
      {
        mergedIntervals.push_back(tempInterval);
        tempInterval = it;
      }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
  }
};

int main()
{
  vector<vector<int>> arr = {{1, 2}, {2, 5}, {6, 7}, {8, 10}};
  Solution sol;

  vector<vector<int>> ans = sol.merge(arr);

  cout << "Merged intervals:\n";
  for (auto v : ans)
  {
    cout << "[" << v[0] << ", " << v[1] << "] ";
  }
  cout << endl;
  return 0;
}
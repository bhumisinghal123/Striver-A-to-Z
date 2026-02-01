/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    int n = intervals.size();
    for (int i = 0; i < n;)
    {

      int start = intervals[i][0];
      int end = intervals[i][1];

      int j = i + 1;
      while (j < n && intervals[j][0] <= end)
      {
        end = max(end, intervals[j][1]);
        j++;
      }

      ans.push_back({start, end});

      i = j;
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> result = sol.merge(intervals);

  for (auto interval : result)
  {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
  int n = arr.size();

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++)
  {
    if (ans.empty() || arr[i][0] > ans.back()[1])
    {
      ans.push_back(arr[i]);
    }
    else
    {
      ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
  }
  return ans;
}

int main()
{
  vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
  vector<vector<int>> ans = mergeOverlappingIntervals(arr);
  cout << "The merged intervals are: " << "\n";
  for (auto it : ans)
  {
    cout << "[" << it[0] << ", " << it[1] << "] ";
  }
  cout << endl;
  return 0;
}

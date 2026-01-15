/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSumIndices(vector<int> &arr, int target)
  {
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (arr[i] + arr[j] == target)
        {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};

int main()
{
  Solution sol;

  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  vector<int> res = sol.twoSumIndices(arr, target);
  cout << "[" << res[0] << ", " << res[1] << "]\n";

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSumIndices(vector<int> &arr, int target)
  {
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int complement = target - arr[i];
      if (mp.find(complement) != mp.end())
      {
        return {mp[complement], i};
      }
      mp[arr[i]] = i;
    }
    return {-1, -1};
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  vector<int> res = sol.twoSumIndices(arr, target);
  cout << "[" << res[0] << ", " << res[1] << "]\n";

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSumIndices(vector<int> &nums, int target)
  {
    int n = nums.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
      int sum = v[left].first + v[right].first;

      if (sum == target)
      {
        return {v[left].second, v[right].second};
      }
      else if (sum < target)
        left++;
      else
        right--;
    }

    return {-1, -1};
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  vector<int> res = sol.twoSumIndices(arr, target);
  cout << "[" << res[0] << ", " << res[1] << "]\n";

  return 0;
}
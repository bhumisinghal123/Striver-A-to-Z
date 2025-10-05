/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    int count = 0;
    for (int start = 0; start < nums.size(); ++start)
    {
      int sum = 0;
      for (int end = start; end < nums.size(); ++end)
      {
        sum += nums[end];
        if (sum == goal)
        {
          count++;
        }
      }
    }
    return count;
  }
};

int main()
{
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  Solution sol;
  cout << sol.numSubarraysWithSum(nums, goal) << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    unordered_map<int, int> prefixSumCOunt;
    int count = 0, sum = 0;
    prefixSumCOunt[0] = 1;

    for (int num : nums)
    {
      sum += num;

      if (prefixSumCOunt.find(sum - goal) != prefixSumCOunt.end())
      {
        count += prefixSumCOunt[sum - goal];
      }
      prefixSumCOunt[sum]++;
    }
    return count;
  }
};

int main()
{
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  Solution sol;
  cout << sol.numSubarraysWithSum(nums, goal) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    return atMost(nums, goal) - atMost(nums, goal - 1);
  }

private:
  int atMost(vector<int> &nums, int k)
  {
    if (k < 0)
      return 0;

    int left = 0;
    int sum = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++)
    {
      sum += nums[right];

      while (sum > k)
      {
        sum -= nums[left];
        left++;
      }
      count += right - left + 1;
    }
    return count;
  }
};

int main()
{
  vector<int> nums = {1, 0, 1, 0, 1};
  int goal = 2;
  Solution sol;
  cout << sol.numSubarraysWithSum(nums, goal) << endl;
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int currentSum = 0;
        for (int i = i; i <= j; i++)
        {
          currentSum += nums[i];
        }

        if (currentSum == k)
          maxLength = max(maxLength, j - i + 1);
      }
    }
    return maxLength;
  }
};

int main()
{
  vector<int> a = {10, 5, 2, 7, 1, 9};
  int k = 15;

  Solution solution;
  int len = solution.longestSubarray(a, k);

  cout << "The length of the longest subarray is: " << len << "\n";
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();

    int maxLen = 0;

    int left = 0, right = 0;

    int sum = nums[0];

    while (right < n)
    {

      while (left <= right && sum > k)
      {
        sum -= nums[left];
        left++;
      }

      if (sum == k)
      {
        maxLen = max(maxLen, right - left + 1);
      }

      right++;
      if (right < n)
        sum += nums[right];
    }

    return maxLen;
  }
};

int main()
{
  vector<int> nums = {10, 5, 2, 7, 1, 9};
  int k = 15;

  Solution sol;

  int ans = sol.longestSubarray(nums, k);

  cout << "The length of longest subarray having sum k is: " << ans;

  return 0;
}

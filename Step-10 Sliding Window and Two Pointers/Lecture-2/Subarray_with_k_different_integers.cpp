/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      unordered_map<int, int> freq;

      for (int j = i; j < n; j++)
      {
        freq[nums[j]]++;
        if (freq.size() == k)
          count++;
        if (freq.size() > k)
          break;
      }
    }
    return count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  cout << sol.subarraysWithKDistinct(nums, k) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int atMostK(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;
    int left = 0, count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
      if (freq[nums[right]] == 0)
      {
        k--;
      }
      freq[nums[right]]++;

      while (k < 0)
      {
        freq[nums[left]]--;
        if (freq[nums[left]] == 0)
        {
          k++;
        }
        left++;
      }
      count += right - left + 1;
    }
    return count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  cout << sol.atMostK(nums, k) - sol.atMostK(nums, k - 1) << endl;
  return 0;
}
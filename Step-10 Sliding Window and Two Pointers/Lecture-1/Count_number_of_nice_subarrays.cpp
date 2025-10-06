/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int count = 0;

    for (int start = 0; start < nums.size(); start++)
    {
      int oddCount = 0;

      for (int end = start; end < nums.size(); end++)
      {
        if (nums[end] % 2 != 0)
          oddCount++;

        if (oddCount > k)
          break;

        if (oddCount == k)
          count++;
      }
    }
    return count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << sol.numberOfSubarrays(nums, k) << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;
    freq[0] = 1;
    int oddCount = 0;
    int result = 0;
    for (int num : nums)
    {
      if (num % 2 == 1)
        oddCount++;
      if (freq.count(oddCount - k))
      {
        result += freq[oddCount - k];
      }
      freq[oddCount]++;
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << sol.numberOfSubarrays(nums, k) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countAtMost(vector<int> &nums, int k)
  {
    int left = 0, res = 0;
    for (int right = 0; right < nums.size(); right++)
    {
      if (nums[right] % 2 != 0)
        k--;

      while (k < 0)
      {
        if (nums[left] % 2 != 0)
          k++;
        left++;
      }
      res += (right - left + 1);
    }
    return res;
  }

  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return countAtMost(nums, k) - countAtMost(nums, k - 1);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  cout << sol.numberOfSubarrays(nums, k) << endl;
  return 0;
}
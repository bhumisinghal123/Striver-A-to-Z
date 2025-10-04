/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int zeros = 0;
      for (int j = i; j < nums.size(); j++)
      {
        if (nums[j] == 0)
        {
          zeros++;
        }
        if (zeros > k)
        {
          break;
        }
        maxLen = max(maxLen, j - i + 1);
      }
    }
    return maxLen;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  cout << sol.longestOnes(nums, k) << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int left = 0;
    int zeros = 0;
    int maxLen = 0;
    for (int right = 0; right < nums.size(); right++)
    {
      if (nums[right] == 0)
      {
        zeros++;
      }
      while (zeros > k)
      {
        if (nums[left] == 0)
        {
          zeros--;
        }
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  cout << sol.longestOnes(nums, k) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int left = 0;
    int zerocount = 0;
    int maxlen = 0;

    for (int right = 0; right < nums.size(); right++)
    {
      if (nums[right] == 0)
      {
        zerocount++;
      }
      if (zerocount > k)
      {
        if (nums[left] == 0)
        {
          zerocount--;
        }
        left++;
      }
      maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  cout << sol.longestOnes(nums, k) << endl;
  return 0;
}
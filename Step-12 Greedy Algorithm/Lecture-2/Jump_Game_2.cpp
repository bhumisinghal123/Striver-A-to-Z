/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    return minJumps(nums, 0);
  }

private:
  int minJumps(vector<int> &nums, int position)
  {
    if (position >= nums.size() - 1)
      return 0;

    if (nums[position] == 0)
      return INT_MAX;

    int miniStep = INT_MAX;

    for (int jump = 1; jump <= nums[position]; jump++)
    {
      int subResult = minJumps(nums, position + jump);

      if (subResult != INT_MAX)
        miniStep = min(miniStep, 1 + subResult);
    }
    return miniStep;
  }
};

int main()
{
  vector<int> nums = {2, 3, 1, 1, 4};

  Solution sol;
  cout << "Minimum number of jumps: " << sol.jump(nums) << endl;

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 1; j <= nums[i] && i + j < n; ++j)
      {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[n - 1];
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << "Minimum jumps: " << sol.jump(nums) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
      farthest = max(farthest, i + nums[i]);

      if (i == currentEnd)
      {
        jumps++;
        currentEnd = farthest;
      }
    }
    return jumps;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 1, 4};
  cout << "Minimum jumps: " << sol.jump(nums) << endl;
  return 0;
}
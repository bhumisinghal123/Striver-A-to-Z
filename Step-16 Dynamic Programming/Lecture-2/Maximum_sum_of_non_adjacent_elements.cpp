/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp)
{
  if (ind == 0)
    return nums[ind];
  if (ind < 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];

  int pick = nums[ind] + f(ind - 2, nums, dp);
  int notPick = 0 + f(ind - 1, nums, dp);

  return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n, -1);
  return f(n - 1, nums, dp);
}

int main()
{
  vector<int> nums = {1, 3, 2, 8, 9};
  cout << maximumNonAdjacentSum(nums);
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumNonAdjacentSum(vector<int> &arr)
  {
    int n = arr.size();

    if (n == 1)
      return arr[0];

    vector<int> dp(n);

    dp[0] = arr[0];

    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
      dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
  }
};

int main()
{
  vector<int> arr = {2, 1, 4, 9};
  Solution obj;
  cout << obj.maximumNonAdjacentSum(arr);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumNonAdjacentSum(vector<int> &nums)
  {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
      int take = nums[i];
      if (i > 1)
        take += prev2;

      int notTake = 0 + prev;

      int curi = max(take, notTake);
      prev2 = prev;
      prev = curi;
    }
    return prev;
  }
};

int main()
{
  vector<int> arr = {2, 1, 4, 9};
  Solution obj;
  cout << obj.maximumNonAdjacentSum(arr);
  return 0;
}

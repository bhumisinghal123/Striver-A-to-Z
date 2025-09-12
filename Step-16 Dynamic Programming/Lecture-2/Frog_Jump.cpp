// Tabulation
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{

  vector<int> height{30, 10, 60, 10, 60, 50};
  int n = height.size();
  vector<int> dp(n, 0);
  dp[0] = 0;
  for (int ind = 1; ind < n; ind++)
  {
    int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
    int jumpTwo = INT_MAX;
    if (ind > 1)
      jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

    dp[ind] = min(jumpOne, jumpTwo);
  }
  cout << dp[n - 1];
}
*/

// Memoization
/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &heights, vector<int> &dp)
{
  if (ind == 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
  int right = INT_MAX;
  if (ind > 1)
    right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
  return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n + 1, -1);
  return f(n - 1, heights, dp);
}

int main()
{
  int n = 6;
  vector<int> heights = {10, 30, 20, 40, 60, 10};
  cout << frogJump(n, heights);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

  vector<int> height{30, 10, 60, 10, 60, 50};
  int n = height.size();
  int prev = 0;
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {

    int jumpTwo = INT_MAX;
    int jumpOne = prev + abs(height[i] - height[i - 1]);
    if (i > 1)
      jumpTwo = prev2 + abs(height[i] - height[i - 2]);

    int cur_i = min(jumpOne, jumpTwo);
    prev2 = prev;
    prev = cur_i;
  }
  cout << prev;
}

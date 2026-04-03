/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];

            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n - 1][tar];
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    cout << findWays(nums, target) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return num[0] == sum;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1);
    prev[0] = curr[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];

            curr[sum] = notTake + take;
        }
        prev = curr;
    }
    return prev[tar];
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    cout << findWays(nums, target) << endl;
    return 0;
}
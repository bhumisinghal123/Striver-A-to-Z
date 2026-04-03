/*
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    int k = totSum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }

    int mini = 1e9;
    for (int s1 = 0; s1 <= totSum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs(totSum - 2 * s1));
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n) << "\n";

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int totSum = 0;
        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }
        vector<bool> prev(totSum + 1, false);
        prev[0] = true;
        if (arr[0] <= totSum)
            prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> cur(totSum + 1, false);
            cur[0] = true;

            for (int target = 1; target <= totSum; target++)
            {
                bool notTaken = prev[target];
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];
                cur[target] = notTaken || taken;
            }
            prev = cur;
        }

        int mini = INT_MAX;
        for (int i = 0; i <= totSum; i++)
        {
            if (prev[i])
            {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    Solution sol;
    cout << "The minimum absolute difference is: " << sol.minSubsetSumDifference(arr, n) << "\n";

    return 0;
}

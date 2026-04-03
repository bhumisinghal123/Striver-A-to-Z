/*
#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);
int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum == 0 && num[0] == 0)
            return 2;
        if (sum == 0 || sum == num[0])
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int notTake = f(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = f(ind - 1, sum - num[ind], num, dp);

    return dp[ind][sum] = (notTake + take) % mod;
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto &it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return false;
    return findWays(arr, (totSum - d) / 2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int d = 1;
    int n = arr.size();
    cout << countPartitions(n, d, arr) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);
int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum == 0 && num[0] == 0)
            return 2;
        if (sum == 0 || sum == num[0])
            return 1;
        return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int notTake = f(ind - 1, sum, num, dp);
    int take = 0;
    if (num[ind] <= sum)
        take = f(ind - 1, sum - num[ind], num, dp);

    return dp[ind][sum] = (notTake + take) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];

            dp[ind][sum] = (notTake + take) % mod;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto &it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return false;
    return findWays(arr, (totSum - d) / 2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int d = 1;
    int n = arr.size();
    cout << countPartitions(n, d, arr) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];

            cur[sum] = (notTake + take) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto &it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return false;
    return findWays(arr, (totSum - d) / 2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int d = 1;
    int n = arr.size();
    cout << countPartitions(n, d, arr) << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        return 0;
    }

    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }

    int notTake = 0 + f(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = val[ind] + f(ind - 1, w - wt[ind], wt, val, dp);
    }
    return dp[ind][w] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(n - 1, maxWeight, weight, value, dp);
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is "
         << knapsack(wt, val, n, W) << endl;

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int w = weight[0]; w <= maxWeight; w++)
        dp[0][w] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (weight[ind] <= w)
            {
                take = value[ind] + dp[ind - 1][w - weight[ind]];
            }
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is "
         << knapsack(wt, val, n, W) << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int w = weight[0]; w <= maxWeight; w++)
        prev[w] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (weight[ind] <= w)
            {
                take = value[ind] + prev[w - weight[ind]];
            }
            prev[w] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is "
         << knapsack(wt, val, n, W) << endl;

    return 0;
}
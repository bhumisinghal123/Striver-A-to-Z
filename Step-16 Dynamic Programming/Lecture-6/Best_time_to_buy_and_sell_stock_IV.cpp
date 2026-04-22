/*
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy == 1)
                {
                    cur[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                }
                else
                    cur[buy][cap] = max(prices[ind] + after[1][cap - 1], 0 + after[0][cap]);
            }
        }
        after = cur;
    }
    return after[1][k];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int tranNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp)
{
    if (ind == n || tranNo == 2 * k)
        return 0;

    if (dp[ind][tranNo] != -1)
    {
        return dp[ind][tranNo];
    }

    if (tranNo % 2 == 0)
    {
        return dp[ind][tranNo] = max(-prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp), 0 + f(ind + 1, tranNo, prices, n, k, dp));
    }
    return dp[ind][tranNo] = max(prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp), 0 + f(ind + 1, tranNo, prices, n, k, dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return f(0, 0, prices, n, k, dp);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<int> after(2 * k + 1, 0);
    vector<int> cur(2 * k + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int tranNo = 2 * k - 1; tranNo >= 0; tranNo--)
        {
            if (tranNo % 2 == 0)
            {
                cur[tranNo] = max(-prices[ind] + after[tranNo + 1], 0 + after[tranNo]);
            }
            else
                cur[tranNo] = max(prices[ind] + after[tranNo + 1], 0 + after[tranNo]);
        }
        after = cur;
    }
    return after[0];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k);

    return 0;
}
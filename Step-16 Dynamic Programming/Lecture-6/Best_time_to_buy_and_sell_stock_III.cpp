/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, int cap, vector<int> &prices, int n)
{
    if (ind == n || cap == 0)
        return 0;

    if (buy == 1)
    {
        return max(-prices[ind] + f(ind + 1, 0, cap, prices, n), 0 + f(ind + 1, 1, cap, prices, n));
    }
    return max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n), 0 + f(ind + 1, 0, cap, prices, n));
}

int maxProfit(vector<int> &prices, int n)
{
    return f(0, 1, 2, prices, n);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
    {
        return dp[ind][buy][cap];
    }

    if (buy == 1)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + f(ind + 1, 0, cap, prices, n, dp), 0 + f(ind + 1, 1, cap, prices, n, dp));
    }
    return dp[ind][buy][cap] = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp), 0 + f(ind + 1, 0, cap, prices, n, dp));
}

int maxProfit(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, n, dp);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 1)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                }
                else
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
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
    return after[1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n);

    return 0;
}
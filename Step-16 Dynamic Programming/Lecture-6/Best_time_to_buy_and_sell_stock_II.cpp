/*
#include <bits/stdc++.h>
using namespace std;

long f(int ind, int buy, long *values, int n)
{
    if (ind == n)
        return 0;

    long profit = 0;

    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n), 0 + f(ind + 1, 1, values, n));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, values, n), 0 + f(ind + 1, 0, values, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return f(0, 1, values, n);
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

long f(int ind, int buy, long *values, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy)
    {
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp), 0 + f(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + f(ind + 1, 1, values, n, dp), 0 + f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, values, n, dp);
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;

            if (buy)
            {
                profit = max(-values[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    vector<long> ahead(2, 0), cur(2, 0);

    ahead[0] = ahead[1] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;

            if (buy)
            {
                profit = max(-values[ind] + ahead[0], 0 + ahead[1]);
            }
            else
            {
                profit = max(values[ind] + ahead[1], 0 + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        curNotBuy = max(values[ind] + aheadBuy, 0 + aheadNotBuy);

        curBuy = max(-values[ind] + aheadNotBuy, 0 + aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}

int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}
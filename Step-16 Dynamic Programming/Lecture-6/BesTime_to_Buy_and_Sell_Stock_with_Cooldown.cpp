/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int> &prices)
{
    int n = prices.size();

    if (ind >= n)
        return 0;

    if (buy == 1)
    {
        return max(-prices[ind] + f(ind + 1, 0, prices), 0 + f(ind + 1, 1, prices));
    }
    return max(prices[ind] + f(ind + 2, 1, prices), 0 + f(ind + 1, 0, prices));
}

int maxProfit(vector<int> &prices)
{
    return f(0, 1, prices);
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    int n = prices.size();

    if (ind >= n)
        return 0;

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    if (buy == 1)
    {
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, dp), 0 + f(ind + 1, 1, prices, dp));
    }
    return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, dp), 0 + f(ind + 1, 0, prices, dp));
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, dp);
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
                dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
        }
    }
    return dp[0][1];
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
    }
    return dp[0][1];
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> cur(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        cur[1] = max(-prices[ind] + front1[0], 0 + front1[1]);
        cur[0] = max(prices[ind] + front2[1], 0 + front1[0]);

        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}

int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "The maximum profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
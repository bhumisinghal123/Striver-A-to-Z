/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<int> &a)
    {
        if (i > j)
            return 0;
        int maxi = INT_MIN;

        for (int ind = i; ind <= j; ind++)
        {
            int cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a) + f(ind + 1, j, a);
            maxi = max(maxi, cost);
        }
        return maxi;
    }

    int maxCoins(vector<int> &a)
    {
        int n = a.size();

        a.push_back(1);
        a.insert(a.begin(), 1);

        return f(1, n, a);
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;
    cout << "Maximum coins obtained: " << sol.maxCoins(nums) << "\n";

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int maxi = INT_MIN;

        for (int ind = i; ind <= j; ind++)
        {
            int cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int> &a)
    {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(1, n, a, dp);
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;
    cout << "Maximum coins obtained: " << sol.maxCoins(nums) << "\n";

    return 0;
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &a)
    {
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                int maxi = INT_MIN;

                for (int ind = i; ind <= j; ind++)
                {
                    int cost = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;
    cout << "Maximum coins obtained: " << sol.maxCoins(nums) << "\n";

    return 0;
}
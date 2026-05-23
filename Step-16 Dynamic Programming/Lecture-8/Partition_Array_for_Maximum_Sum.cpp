/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int ind, vector<int> &nums, int k)
    {
        if (ind == nums.size())
            return 0;

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int i = ind; i < min(ind + k, (int)nums.size()); i++)
        {
            len++;
            maxi = max(maxi, nums[i]);
            int sum = len * maxi + f(i + 1, nums, k);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int> &nums, int k)
    {
        int n = nums.size();

        return f(0, nums, k);
    }
};

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    Solution sol;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << "\n";

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int ind, vector<int> &nums, int k, vector<int> &dp)
    {
        if (ind == nums.size())
            return 0;

        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int i = ind; i < min(ind + k, (int)nums.size()); i++)
        {
            len++;
            maxi = max(maxi, nums[i]);
            int sum = len * maxi + f(i + 1, nums, k, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, -1);

        return f(0, nums, k, dp);
    }
};

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    Solution sol;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << "\n";

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[n] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

            for (int i = ind; i < min(ind + k, n); i++)
            {
                len++;
                maxi = max(maxi, nums[i]);
                int sum = len * maxi + dp[i + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }

        return dp[0];
    }
};

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    Solution sol;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << "\n";

    return 0;
}
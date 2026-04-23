/*
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev_ind + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int lengthOfLIS = longestIncreasingSubsequence(nums, n);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + next[ind + 1]);
            }
            cur[prev_ind + 1] = len;
        }
        next = cur;
    }
    return next[-1 + 1];
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int lengthOfLIS = longestIncreasingSubsequence(nums, n);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int lengthOfLIS = longestIncreasingSubsequence(nums, n);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
    cout << endl;
    return maxi;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int lengthOfLIS = longestIncreasingSubsequence(nums, n);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
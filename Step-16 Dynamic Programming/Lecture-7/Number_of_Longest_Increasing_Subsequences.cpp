#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
            {
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            nos += cnt[i];
    }
    return nos;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};
    cout << "The count of Longest Increasing Subsequences (LIS) is "
         << findNumberOfLIS(arr) << endl;

    return 0;
}
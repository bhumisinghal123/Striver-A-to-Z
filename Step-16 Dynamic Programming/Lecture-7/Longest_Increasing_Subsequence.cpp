#include <bits/stdc++.h>
using namespace std;

int f(int ind, int prev_ind, vector<int> &arr, int n)
{
    if (ind == n)
        return 0;

    int len = 0 + f(ind + 1, prev_ind, arr, n);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
    {
        len = max(len, 1 + f(ind + 1, ind, arr, n));
    }
    return len;
}

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    return f(0, -1, arr, n);
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int lengthOfLIS = longestIncreasingSubsequence(nums, n);

    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;

    return 0;
}
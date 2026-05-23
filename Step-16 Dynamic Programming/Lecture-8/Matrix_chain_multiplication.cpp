/*
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
        if (steps < mini)
            mini = steps;
    }
    return mini;
}

int matrixMutliplication(vector<int> &arr, int n)
{
    return f(1, n - 1, arr);
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    cout << "Minimum number of multiplications is: "
         << matrixMutliplication(arr, n) << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    int mini = 1e9;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        if (steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
}

int matrixMutliplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(1, n - 1, arr, dp);
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    cout << "Minimum number of multiplications is: "
         << matrixMutliplication(arr, n) << endl;

    return 0;
}
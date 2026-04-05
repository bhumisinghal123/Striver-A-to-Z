/*
#include <bits/stdc++.h>
using namespace std;

long f(int ind, int T, vector<int> &a)
{
    if (ind == 0)
    {
        return (T % a[0] == 0);
    }

    long notTake = f(ind - 1, T, a);
    long take = 0;
    if (a[ind] <= T)
        take = f(ind, T - a[ind], a);
    return take + notTake;
}

long countWaysToMakeChange(vector<int> &denominations, int n, int value)
{
    return f(n - 1, value, denominations);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

long f(int ind, int T, vector<int> &a, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (T % a[0] == 0);
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    long notTake = f(ind - 1, T, a, dp);
    long take = 0;
    if (a[ind] <= T)
        take = f(ind, T - a[ind], a, dp);
    return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange(vector<int> &denominations, int n, int value)
{
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int> &a, int n, int value)
{
    vector<vector<int>> dp(n, vector<int>(value + 1, 0));

    for (int T = 0; T <= value; T++)
    {
        dp[0][T] = (T % a[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = dp[ind - 1][T];
            long take = 0;
            if (a[ind] <= T)
                take = dp[ind][T - a[ind]];
            dp[ind][T] = take + notTake;
        }
    }

    return dp[n - 1][value];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int> &a, int n, int value)
{
    vector<vector<int>> dp(n, vector<int>(value + 1, 0));
    vector<int> prev(value + 1, 0), curr(value + 1, 0);

    for (int T = 0; T <= value; T++)
    {
        prev[T] = (T % a[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long notTake = prev[T];
            long take = 0;
            if (a[ind] <= T)
                take = curr[T - a[ind]];
            curr[T] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();

    cout << "The total number of ways is " << countWaysToMakeChange(arr, n, target) << endl;
    return 0;
}
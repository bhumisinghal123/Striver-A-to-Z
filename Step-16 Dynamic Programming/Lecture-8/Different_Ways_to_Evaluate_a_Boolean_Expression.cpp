/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;

    long long f(int i, int j, int isTrue, string &exp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
            {
                return exp[i] == 'T';
            }
            else
            {
                return exp[i] == 'F';
            }
        }
        long long ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            long long lT = f(i, ind - 1, 1, exp);
            long long lF = f(i, ind - 1, 0, exp);
            long long rT = f(ind + 1, j, 1, exp);
            long long rF = f(ind + 1, j, 0, exp);

            if (exp[ind] == '&')
            {
                if (isTrue)
                    ways = (ways + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
            }
            else if (exp[ind] == '|')
            {
                if (isTrue)
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rF * lF) % mod) % mod;
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
        }
        return ways;
    }

    int evaluateExp(string &exp)
    {
        int n = exp.size();
        return f(0, n - 1, 1, exp);
    }
};

int main()
{
    string exp = "F|T^F";
    Solution sol;
    cout << sol.evaluateExp(exp) << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;

    long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
            {
                return exp[i] == 'T';
            }
            else
            {
                return exp[i] == 'F';
            }
        }

        if (dp[i][j][isTrue] != -1)
        {
            return dp[i][j][isTrue];
        }

        long long ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            long long lT = f(i, ind - 1, 1, exp, dp);
            long long lF = f(i, ind - 1, 0, exp, dp);
            long long rT = f(ind + 1, j, 1, exp, dp);
            long long rF = f(ind + 1, j, 0, exp, dp);

            if (exp[ind] == '&')
            {
                if (isTrue)
                    ways = (ways + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
            }
            else if (exp[ind] == '|')
            {
                if (isTrue)
                    ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rF * lF) % mod) % mod;
            }
            else
            {
                if (isTrue)
                {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }

    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));

        return f(0, n - 1, 1, exp, dp);
    }
};

int main()
{
    string exp = "F|T^F";
    Solution sol;
    cout << sol.evaluateExp(exp) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;

    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                if (i > j)
                    continue;

                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {
                    if (i == j)
                    {
                        if (isTrue == 1)
                            dp[i][j][isTrue] = exp[i] == 'T';
                        else
                            dp[i][j][isTrue] = exp[i] == 'F';
                        continue;
                    }

                    long long ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind += 2)
                    {
                        long long lT = dp[i][ind - 1][1];
                        long long lF = dp[i][ind - 1][0];
                        long long rT = dp[ind + 1][j][1];
                        long long rF = dp[ind + 1][j][0];

                        if (exp[ind] == '&')
                        {
                            if (isTrue)
                                ways = (ways + (rT * lT) % mod) % mod;
                            else
                                ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
                        }
                        else if (exp[ind] == '|')
                        {
                            if (isTrue)
                                ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rT * lT) % mod) % mod;
                            else
                                ways = (ways + (rF * lF) % mod) % mod;
                        }
                        else
                        {
                            if (isTrue)
                            {
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            }
                            else
                            {
                                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }
};

int main()
{
    string exp = "F|T^F";
    Solution sol;
    cout << sol.evaluateExp(exp) << endl;
    return 0;
}
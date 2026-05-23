/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s)
    {
        if (i == n)
            return 0;

        int minCost = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }

    int minCut(string &s)
    {
        int n = s.size();

        return f(0, n, s) - 1;
    }
};

int main()
{
    string s = "aab";

    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << "\n";

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int minCost = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + f(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string &s)
    {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, n, s, dp) - 1;
    }
};

int main()
{
    string s = "aab";

    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << "\n";

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string &s)
    {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;

            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};

int main()
{
    string s = "aab";

    Solution sol;
    cout << "Minimum cuts needed: " << sol.minCut(s) << "\n";

    return 0;
}
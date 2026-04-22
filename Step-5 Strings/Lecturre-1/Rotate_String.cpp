/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string &s, string &goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == goal)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s = "rotation";
    string goal = "tionrota";
    if (sol.rotateString(s, goal))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string &s, string &goal)
    {
        if (s.length() != goal.length())
            return false;
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};

int main()
{
    Solution sol;
    string s = "rotation";
    string goal = "tionrota";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl;

    return 0;
}
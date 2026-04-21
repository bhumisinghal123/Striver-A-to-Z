#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largeOddNum(string &s)
    {
        int ind = -1;
        int i;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if ((s[i] - '0') % 2 == 1)
            {
                ind = i;
                break;
            }
        }
        i = 0;
        while (i <= ind && s[i] == '0')
            i++;

        return s.substr(i, ind - i + 1);
    }
};

int main()
{
    Solution solution;
    string num = "504";
    string result = solution.largeOddNum(num);
    cout << "Largest odd number: " << result << endl;
    return 0;
}
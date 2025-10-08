#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int> &student, vector<int> &cookies)
  {
    sort(student.begin(), student.end());
    sort(cookies.begin(), cookies.end());

    vector<vector<int>> memo(student.size(), vector<int>(cookies.size(), -1));
    return helper(0, 0, student, cookies, memo);
  }

private:
  int helper(int studentIndex, int cookieIndex, vector<int> &student, vector<int> &cookie, vector<vector<int>> &memo)
  {
    if (studentIndex >= student.size() || cookieIndex >= cookie.size())
    {
      return 0;
    }

    if (memo[studentIndex][cookieIndex] != -1)

      return memo[studentIndex][cookieIndex];
    int result = 0;

    if (cookie[cookieIndex] >= student[studentIndex])
    {
      result = max(result, 1 + helper(studentIndex + 1, cookieIndex + 1, student, cookie, memo));
    }
    result = max(result, helper(studentIndex, cookieIndex + 1, student, cookie, memo));

    return memo[studentIndex][cookieIndex] = result;
  }
};

int main()
{
  Solution sol;
  vector<int> student = {1, 2};
  vector<int> cookies = {1, 2, 3};
  cout << sol.findContentChildren(student, cookies) << endl;
  return 0;
}

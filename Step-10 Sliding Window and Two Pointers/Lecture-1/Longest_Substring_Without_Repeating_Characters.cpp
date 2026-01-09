/*
#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
    if (str.size() == 0)
      return 0;
    int maxans = 0;
    for (int i = 0; i < str.length(); i++)
    {
      unordered_set<char> set;
      for (int j = i; j < str.length(); j++)
      {
        if (set.find(str[j]) != set.end())
        {
          maxans = max(maxans, j - i);
          break;
        }
        set.insert(str[j]);
        maxans = max(maxans, j - i + 1);
      }
    }
    return maxans;
}

int main()
{
  string str;
  cin >> str;
  cout << solve(str) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int solve(string str)
{
  if (str.size() == 0)
    return 0;
  int maxans = INT_MIN;
  unordered_set<int> set;
  int l = 0;
  for (int r = 0; r < str.length(); r++)
  {
    if (set.find(str[r]) != set.end())
    {
      while (l < r && set.find(str[r]) != set.end())
      {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

int main()
{
  string str;
  cin >> str;
  cout << solve(str) << endl;
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  int n = s.size(), m = t.size();
  if (m > n)
    return "";

  int minLen = INT_MAX;
  int startIndex = -1;

  vector<int> hash(256, 0);
  for (int j = 0; j < m; j++)
    hash[t[j]]++;

  int count = 0;
  int i = 0, j = 0;

  while (j < n)
  {
    if (hash[s[j]] > 0)
      count++;

    hash[s[j]]--;

    while (count == m)
    {
      if (j - i + 1 < minLen)
      {
        minLen = j - i + 1;
        startIndex = i;
      }

      hash[s[i]]++;
      if (hash[s[i]] > 0)
        count--;
      i++;
    }
    j++;
  }

  if (startIndex == -1)
    return "";
  return s.substr(startIndex, minLen);
}

int main()
{
  string s = "ddaaoabbca";
  string t = "abc";
  cout << "Minimum window substring: " << minWindow(s, t);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
  int n = s.size(), m = t.size();
  if (m > n)
    return "";

  vector<int> hash(256, 0);
  for (int i = 0; i < m; i++)
    hash[t[i]]++;

  int l = 0, r = 0;
  int count = 0;
  int minLen = INT_MAX;
  int startIndex = -1;

  while (r < n)
  {
    if (hash[s[r]] > 0)
      count++;

    hash[s[r]]--;

    while (count == m)
    {
      if (r - l + 1 < minLen)
      {
        minLen = r - l + 1;
        startIndex = l;
      }

      hash[s[l]]++;
      if (hash[s[l]] > 0)
        count--;

      l++;
    }

    r++;
  }

  if (startIndex == -1)
    return "";

  return s.substr(startIndex, minLen);
}

int main()
{
  string s = "ddaaoabbca";
  string t = "abc";

  cout << "Minimum window substring: " << minWindow(s, t);
  return 0;
}

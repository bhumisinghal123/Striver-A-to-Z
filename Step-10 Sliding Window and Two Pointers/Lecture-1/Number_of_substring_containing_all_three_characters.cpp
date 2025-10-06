/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
      vector<int> freq(3, 0);
      for (int j = i; j < n; j++)
      {
        freq[s[j] - 'a']++;
        if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        {
          count++;
        }
      }
    }
    return count;
  }
};

int main()
{
  Solution sol;
  string s = "abcabc";
  cout << sol.numberOfSubstrings(s) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numberOfSubarrays(string s)
  {
    vector<int> freq(3, 0);
    int res = 0;
    int left = 0;
    for (int right = 0; right < s.length(); right++)
    {
      freq[s[right] - 'a']++;
      while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
      {
        res += (s.length() - right);
        freq[s[left] - 'a']--;
        left++;
      }
    }
    return res;
  }
};

int main()
{
  Solution sol;
  string s = "abcabc";
  cout << sol.numberOfSubarrays(s) << endl;
  return 0;
}
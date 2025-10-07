/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstringkDistinct(string s, int k)
  {
    int maxLength = 0;
    for (int i = 0; i < s.size(); i++)
    {
      unordered_map<char, int> freq;
      for (int j = i; j < s.size(); j++)
      {
        freq[s[j]]++;
        if (freq.size() > k)
          break;
        maxLength = max(maxLength, j - i + 1);
      }
    }
    return maxLength;
  }
};

int main()
{
  Solution sol;
  string s = "eceba";
  int k = 2;
  cout << sol.lengthOfLongestSubstringkDistinct(s, k) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstringkDistinct(string s, int k)
  {
    if (k == 0 || s.empty())
      return 0;
    unordered_map<char, int> freq;
    int left = 0;
    int maxLen = 0;
    for (int right = 0; right < s.length(); right++)
    {
      freq[s[right]]++;
      while (freq.size() > k)
      {
        freq[s[left]]--;
        if (freq[s[left]] == 0)
        {
          freq.erase(s[left]);
        }
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

int main()
{
  Solution sol;
  string s = "eceba";
  int k = 2;
  cout << sol.lengthOfLongestSubstringkDistinct(s, k) << endl;
  return 0;
}
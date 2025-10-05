/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++)
    {
      vector<int> freq(26, 0);
      int maxFreq = 0;
      for (int j = i; j < s.length(); j++)
      {
        freq[s[j] - 'A']++;
        maxFreq = max(maxFreq, freq[s[j] - 'A']);
        int windowLength = j - i + 1;
        int replace = windowLength - maxFreq;
        if (replace <= k)
        {
          maxLength = max(maxLength, windowLength);
        }
      }
    }
    return maxLength;
  }
};

int main()
{
  Solution sol;
  string s = "AABABBA";
  int k = 1;
  cout << sol.characterReplacement(s, k) << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    unordered_map<int, int> freq;
    int left = 0;
    int max_freq = 0;
    int max_length = 0;
    for (int right = 0; right < s.length(); right++)
    {
      freq[s[right]]++;
      max_freq = max(max_freq, freq[s[right]]);
      while ((right - left + 1) - max_freq > k)
      {
        freq[s[left]]--;
        left++;
      }
      max_length = max(max_length, right - left + 1);
    }
    return max_length;
  }
};

int main()
{
  Solution sol;
  string s = "AABABBA";
  int k = 1;
  cout << sol.characterReplacement(s, k) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    vector<int> freq(26, 0);
    int left = 0;
    int right = 0;
    int maxCount = 0;
    int maxLength = 0;
    while (right < s.size())
    {
      freq[s[right] - 'A']++;
      maxCount = max(maxCount, freq[s[right] - 'A']);
      while ((right - left + 1) - maxCount > k)
      {
        freq[s[left] - 'A']--;
        left++;
      }
      maxLength = max(maxLength, right - left + 1);
      right++;
    }
    return maxLength;
  }
};

int main()
{
  Solution sol;
  string s = "AABABBA";
  int k = 1;
  cout << sol.characterReplacement(s, k) << endl;
  return 0;
}
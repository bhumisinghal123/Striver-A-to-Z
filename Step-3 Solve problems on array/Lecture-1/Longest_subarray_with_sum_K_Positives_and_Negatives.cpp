/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int currentSum = 0;
        for (int ind = i; ind <= j; ind++)
        {
          currentSum += nums[ind];
        }

        if (currentSum == k)
          maxLength = max(maxLength, j - i + 1);
      }
    }
    return maxLength;
  }
};

int main()
{
  vector<int> a = {-1, 1, 1};
  int k = 1;

  Solution solution;
  int len = solution.longestSubarray(a, k);

  cout << "The length of the longest subarray is: " << len << "\n";
  return 0;
}
*/

/*
include <bits/stdc++.h>
using namespace std;

class SubarraySolver
{
public:
  int getLongestSubarray(vector<int> &a, int k)
  {
    int n = a.size();
    int len = 0;

    for (int i = 0; i < n; i++)
    {
      int s = 0;

      for (int j = i; j < n; j++)
      {
        s += a[j];

        if (s == k)
        {
          len = max(len, j - i + 1);
        }
      }
    }
    return len;
  }
};


int main()
{
  vector<int> a = {-1, 1, 1};
  int k = 1;

  SubarraySolver solver;
  int len = solver.getLongestSubarray(a, k);

  cout << "The length of the longest subarray is: " << len << "\n";
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumNegative(vector<int> a, long long k)
{
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for (int i = 0; i < a.size(); i++)
  {
    sum += a[i];
    if (sum == k)
    {
      maxLen = (maxLen, i + 1);
    }
    long long rem = sum - k;
    if (preSumMap.find(rem) != preSumMap.end())
    {
      int len = i - preSumMap[rem];
      maxLen = (maxLen, len);
    }
    if (preSumMap.find(sum) == preSumMap.end())
    {
      preSumMap[sum] = i;
    }
  }
  return maxLen;
}

int main()
{
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << longestSubarrayWithSumNegative(arr, k);
  return 0;
}

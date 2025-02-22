#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumPositive(vector<int> a, long long k)
{
  /*
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
  */
  int left = 0, right = 0;
  long long sum = a[0];
  int maxLen = 0;
  int n = a.size();
  while (right < n)
  {
    while (left <= right && sum > k)
    {
      sum -= a[left];
      left++;
    }
    if (sum == k)
    {
      maxLen = (maxLen, right - left + 1);
    }
    right++;
    if (right < n)
      sum += a[right];
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
  cout << longestSubarrayWithSumPositive(arr, k);
  return 0;
}
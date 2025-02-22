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
#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k)
{
  sort(nums.begin(), nums.end());
  long long int maxFreq = 0, l = 0, total = 0, n = nums.size();

  for (int r = 0; r < n; r++)
  {
    total += nums[r];

    if (l + 1 <= r && (nums[r] * (r - l + 1)) > total + k)
    {
      total -= nums[l];
      l++;
    }
    maxFreq = max(maxFreq, r - l + 1);
  }
  return maxFreq;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int k;
  cin >> k;
  cout << maxFrequency(nums, k);
  return 0;
}
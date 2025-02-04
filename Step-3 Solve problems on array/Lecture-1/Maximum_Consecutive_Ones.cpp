#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int maxi = 0;
  int cnt = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      cnt++;
      maxi = max(maxi, cnt);
    }
    else
    {
      cnt = 0;
    }
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << findMaxConsecutiveOnes(a) << endl;
  return 0;
}

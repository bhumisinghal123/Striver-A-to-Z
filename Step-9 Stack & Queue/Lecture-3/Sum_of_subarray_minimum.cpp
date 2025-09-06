#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int sumSubarrayMins(vector<int> &arr)
{
  long long sum = 0;
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    int mini = arr[i];
    for (int j = i; j < n; j++)
    {
      mini = min(mini, arr[j]);
      sum = (sum + mini) % mod;
    }
  }
  return (int)sum;
}

int main()
{
  vector<int> arr = {3, 1, 2, 6, 5};
  cout << sumSubarrayMins(arr);
  return 0;
}

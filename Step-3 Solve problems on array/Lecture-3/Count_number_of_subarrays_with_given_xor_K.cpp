#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int k)
{
  int xr = 0;
  map<int, int> mpp;
  mpp[xr]++;
  int cnt = 0;
  for (int i = 0; i < a.size(); i++)
  {
    xr = xr ^ a[i];
    int x = xr ^ k;
    cnt += mpp[x];
    mpp[xr]++;
  }
  return cnt;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << subarraysWithSumK(arr, n);
  return 0;
}
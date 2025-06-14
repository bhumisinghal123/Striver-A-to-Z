#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr, int n)
{
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[low] <= arr[high])
    {
      ans = min(ans, arr[low]);
      break;
    }
    if (arr[low] <= arr[mid])
    {
      ans = min(ans, arr[low]);
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
      ans = min(ans, arr[mid]);
    }
  }
  return ans;
}

int main()
{
  vector<int> a = {5, 6, 1, 2, 3, 4};
  int n = 6;
  int ans = findMin(a, n);
  cout << "The minimum in the array is: " << ans << endl;
  return 0;
}
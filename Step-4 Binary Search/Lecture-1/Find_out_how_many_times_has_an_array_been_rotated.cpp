#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr, int n)
{
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  int index = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[low] <= arr[high])
    {
      if (arr[low] < ans)
      {
        index = low;
        ans = arr[low];
      }
      break;
    }
    if (arr[low] <= arr[mid])
    {
      if (arr[low] < ans)
      {
        index = low;
        ans = arr[low];
      }
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
      if (arr[mid] < ans)
      {
        index = mid;
        ans = arr[mid];
      }
    }
  }
  return index;
}

int main()
{
  vector<int> a = {5, 6, 1, 2, 3, 4};
  int n = 6;
  int index = findMin(a, n);
  cout << "The minimum in the array is: " << index << endl;
  return 0;
}
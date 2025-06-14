/*
#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr)
{
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    if ((i == 0 || arr[i - 1] < arr[i]) && ((i == n - 1) || arr[i] > arr[i + 1]))
      return i;
  }
  return -1;
}

int main()
{
  vector<int> a = {1, 2, 1, 3, 4, 5};
  int n = 6;
  int ans = peakElement(a);
  cout << "The index of peak element is: " << ans << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr)
{
  int n = arr.size();
  if (n == 1)
    return 0;
  if (arr[0] > arr[1])
    return 0;
  if (arr[n - 1] > arr[n - 2])
    return n - 1;

  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
      return mid;
    }
    else if (arr[mid] > arr[mid - 1])
    {
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  vector<int> a = {1, 2, 1, 3, 4, 5};
  int n = 6;
  int ans = peakElement(a);
  cout << "The index of peak element is: " << ans << endl;
  return 0;
}
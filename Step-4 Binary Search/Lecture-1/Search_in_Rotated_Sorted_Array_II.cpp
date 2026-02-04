/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
  {
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == k)
        return true;
    }
    return false;
  }
};

int main()
{
  vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  int k = 3;

  Solution obj;
  bool ans = obj.searchInARotatedSortedArrayII(arr, k);

  if (!ans)
    cout << "Target is not present.\n";
  else
    cout << "Target is present in the array.\n";

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int x)
{
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      return true;
    if (arr[low] == arr[mid] && arr[mid] == arr[high])
    {
      low++, high--;
      continue;
    }

    if (arr[low] <= arr[mid])
    {
      if (arr[low] <= x && x <= arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (arr[mid] <= x && x <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return false;
}

int main()
{
  vector<int> a = {3, 4, 5, 1, 2, 3, 3, 3};
  int n = 8, x = 1;
  bool ans = search(a, n, x);
  if (!ans)
    cout << "The target is not present" << endl;
  else
    cout << "The target is present in the array " << endl;
  return 0;
}
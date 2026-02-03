/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == target)
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  Solution obj;
  int index = obj.search(nums, target);

  cout << index << endl;

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
      return mid;

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
  return -1;
}

int main()
{
  vector<int> a = {6, 7, 8, 1, 2, 3, 4, 5};
  int n = 8, x = 1;
  int ind = search(a, n, x);
  if (ind == -1)
    cout << "The target is not present" << endl;
  else
    cout << "The target is present at index " << ind << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
  int n = nums.size();
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (nums[mid] == target)
      return mid;
    else if (target > nums[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  vector<int> a = {1, 3, 4, 5, 6, 7, 8, 9};
  int target = 6;
  int ind = binarySearch(a, target);
  if (ind == -1)
    cout << "The target is not present" << endl;
  else
    cout << "The target is present at index " << ind << endl;
  return 0;
}
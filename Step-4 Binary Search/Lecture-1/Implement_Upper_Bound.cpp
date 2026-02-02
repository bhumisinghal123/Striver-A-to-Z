/*
#include <bits/stdc++.h>
using namespace std;

class UpperBoundFinder
{
public:
  int upperBound(vector<int> &arr, int x, int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > x)
      {
        return i;
      }
    }
    return n;
  }
};

int main()
{
  vector<int> arr = {3, 5, 8, 9, 15, 19};
  int n = arr.size();
  int x = 9;

  UpperBoundFinder finder;
  int ind = finder.upperBound(arr, x, n);

  cout << "The upper bound is the index: " << ind << "\n";
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int n, int x)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (nums[mid] > x)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
}

int main()
{
  vector<int> a = {1, 2, 3, 3, 5, 8, 8, 9, 9, 11};
  int n = 10, x = 9;
  int ind = upperBound(a, n, x);
  cout << "The Upper bound is the index: " << ind << "\n";
  return 0;
}
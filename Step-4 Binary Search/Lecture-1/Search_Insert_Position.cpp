#include <bits/stdc++.h>
using namespace std;

int insertPos(vector<int> &nums, int n, int x)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (nums[mid] >= x)
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
  int ind = insertPos(a, n, x);
  cout << "The lower bound is the index: " << ind << "\n";
  return 0;
}
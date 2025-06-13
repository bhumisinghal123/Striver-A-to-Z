/*
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int n, int x)
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

pair<int, int> firstAndLastPostion(vector<int> &arr, int n, int k)
{
  int lb = lowerBound(arr, n, k);
  if (lb == n || arr[lb] != k)
    return {-1, -1};
  return {lb, upperBound(arr, n, k) - 1};
}
int main()
{
  vector<int> a = {1, 2, 2, 6, 8, 8, 11, 13};
  int n = 8, k = 8;
  pair<int, int> ans = firstAndLastPostion(a, n, k);
  cout << "The first and last position are: " << ans.first << " and " << ans.second << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int x)
{
  int low = 0, high = n - 1;
  int first = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
      first = mid;
      high = mid - 1;
    }
    else if (arr[mid] < x)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return first;
}

int lastOccurence(vector<int> &arr, int n, int x)
{
  int low = 0, high = n - 1;
  int last = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
      last = mid;
      low = mid + 1;
    }
    else if (arr[mid] < x)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return last;
}

pair<int, int> firstAndLastPostion(vector<int> &arr, int n, int x)
{
  int first = firstOccurence(arr, n, x);
  if (first == -1)
    return {-1, -1};
  int last = lastOccurence(arr, n, x);
  return {first, last};
}

int count(vector<int> &arr, int n, int x)
{
  pair<int, int> ans = firstAndLastPostion(arr, n, x);
  if (ans.first == -1)
    return 0;
  return ans.second - ans.first + 1;
}

int main()
{
  vector<int> a = {1, 2, 2, 6, 8, 8, 11, 13};
  int n = 8, k = 8;
  int ans = count(a, n, k);
  cout << "The number of occurence are: " << ans << endl;
  return 0;
  return 0;
}
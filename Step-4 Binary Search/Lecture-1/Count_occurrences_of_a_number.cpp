/*
#include <bits/stdc++.h>
using namespace std;
int count(vector<int> &arr, int n, int x)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {

    if (arr[i] == x)
      cnt++;
  }
  return cnt;
}

int main()
{
  vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
  int n = 8, x = 8;
  int ans = count(arr, n, x);
  cout << "The number of occurrences is: "
       << ans << "\n";
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
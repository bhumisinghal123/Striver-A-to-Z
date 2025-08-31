/*
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++)
  {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0)
    {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n)
    {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int main()
{
  vector<int> arr;
  arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++)
  {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++)
  {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}

int main()
{
  vector<int> arr;
  arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
  int n = arr.size();
  int lMax = 0, rMax = 0;
  int total = 0;
  int l = 0, r = n - 1;

  while (l < r)
  {
    if (arr[l] <= arr[r])
    {
      if (lMax > arr[l])
      {
        total += lMax - arr[l];
      }
      else
      {
        lMax = arr[l];
      }
      l++;
    }
    else
    {
      if (rMax > arr[r])
      {
        total += rMax - arr[r];
      }
      else
      {
        rMax = arr[r];
      }
      r--;
    }
  }
  return total;
}

int main()
{
  vector<int> arr;
  arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
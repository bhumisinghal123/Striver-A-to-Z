/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findRotations(vector<int> &arr)
  {
    int n = arr.size();
    int minVal = arr[0];
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
      if (arr[i] < minVal)
      {
        minVal = arr[i];
        minIndex = i;
      }
    }

    return minIndex;
  }
};

int main()
{
  Solution obj;

  vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

  int rotations = obj.findRotations(arr);

  cout << rotations << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      return i + 1;
    }
  }
  return 0;
}

int main()
{
  vector<int> arr = {3, 4, 5, 1, 2};
  int rotations = findRotationCount(arr);
  cout << rotations << endl;
  return 0;
}
*/

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
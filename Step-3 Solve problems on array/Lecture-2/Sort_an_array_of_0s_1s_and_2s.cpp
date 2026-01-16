/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortZeroOneTwo(vector<int> &nums)
  {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        count0++;
      else if (nums[i] == 1)
        count1++;
      else
        count2++;
    }

    int index = 0;

    while (count0--)
    {
      nums[index++] = 0;
    }

    while (count1--)
    {
      nums[index++] = 1;
    }

    while (count2--)
    {
      nums[index++] = 2;
    }
  }
};

int main()
{
  vector<int> nums = {1, 0, 2, 1, 0};

  Solution obj;
  obj.sortZeroOneTwo(nums);

  for (int x : nums)
  {
    cout << x << " ";
  }

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sortZeroOneTwo(vector<int> &nums)
  {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        cnt0++;
      else if (nums[i] == 1)
        cnt1++;
      else
        cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
    {
      nums[i] = 0;
    }

    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
      nums[i] = 1;
    }

    for (int i = cnt0 + cnt1; i < nums.size(); i++)
    {
      nums[i] = 2;
    }
  }
};

int main()
{
  vector<int> nums = {0, 2, 1, 2, 0, 1};

  Solution sol;
  sol.sortZeroOneTwo(nums);

  cout << "After sorting:" << endl;
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{
  int low = 0, mid = 0, high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    else if (arr[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sortArray(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}

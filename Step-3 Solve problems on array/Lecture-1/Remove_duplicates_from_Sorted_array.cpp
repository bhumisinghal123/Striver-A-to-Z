/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    unordered_set<int> seen;

    int index = 0;

    for (int num : nums)
    {
      if (seen.find(num) == seen.end())
      {
        seen.insert(num);

        nums[index] = num;

        index++;
      }
    }
    return index;
  }
};

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  Solution sol;
  int k = sol.removeDuplicates(nums);

  cout << "k = " << k << "\nArray after removing duplicates: ";
  for (int i = 0; i < k; i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (arr[i] != arr[j])
    {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  return i + 1;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int newSize = removeDuplicate(arr, n);
  for (int k = 0; k < newSize; k++)
  {
    cout << arr[k] << " ";
  }
  cout << endl;

  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextPermutation(vector<int> &nums)
  {
    vector<vector<int>> all;

    sort(nums.begin(), nums.end());
    do
    {
      all.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    for (int i = 0; i < all.size(); i++)
    {
      if (all[i] == nums)
      {
        if (i == all.size() - 1)
          return all[0];
        return all[i + 1];
      }
    }

    return nums;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3};

  vector<int> result = sol.nextPermutation(nums);

  for (int x : result)
    cout << x << " ";
  cout << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
  int ind = -1;
  int n = A.size();
  for (int i = n - 2; i >= 0; i--)
  {
    if (A[i] < A[i + 1])
    {
      ind = i;
      break;
    }
  }

  if (ind == -1)
  {
    reverse(A.begin(), A.end());
    return A;
  }

  for (int i = n - 1; i > ind; i--)
  {
    if (A[i] > A[ind])
    {
      swap(A[i], A[ind]);
      break;
    }
  }
  reverse(A.begin() + ind + 1, A.end());
  return A;
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
  vector<int> result = nextGreaterPermutation(arr);
  for (int i = 0; i < n; i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}
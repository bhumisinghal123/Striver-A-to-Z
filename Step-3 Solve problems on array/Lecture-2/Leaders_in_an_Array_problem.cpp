/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> leaders(vector<int> &nums)
  {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      bool leader = true;

      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[j] >= nums[i])
        {
          leader = false;
          break;
        }
      }

      if (leader)
      {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};


int main()
{
  vector<int> nums = {1, 2, 5, 3, 1, 2};

  Solution finder;

  vector<int> ans = finder.leaders(nums);

  cout << "Leaders in the array are: ";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
  vector<int> ans;
  int maxi = INT_MIN;
  int n = a.size();
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] > maxi)
    {
      ans.push_back(a[i]);
    }
    maxi = max(maxi, a[i]);
  }

  sort(ans.begin(), ans.end());
  return ans;
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
  vector<int> result = superiorElements(arr);
  for (int i = 0; i < n; i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}
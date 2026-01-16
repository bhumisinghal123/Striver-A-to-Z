/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {

      int cnt = 0;

      for (int j = 0; j < n; j++)
      {
        if (nums[j] == nums[i])
        {
          cnt++;
        }
      }

      if (cnt > (n / 2))
      {
        return nums[i];
      }
    }

    return -1;
  }
};

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

  Solution sol;

  int ans = sol.majorityElement(arr);

  cout << "The majority element is: " << ans << endl;

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v)
{

  map<int, int> mpp;
  for (int i = 0; i < v.size(); i++)
  {
    mpp[v[i]]++;
  }
  for (auto it : mpp)
  {
    if (it.second > (v.size() / 2))
    {
      return it.first;
    }
  }
  return -1;
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
  cout << majorityElement(arr);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    int n = nums.size();

    int cnt = 0;

    int el;

    for (int i = 0; i < n; i++)
    {
      if (cnt == 0)
      {
        cnt = 1;
        el = nums[i];
      }
      else if (el == nums[i])
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == el)
      {
        cnt1++;
      }
    }

    if (cnt1 > (n / 2))
    {
      return el;
    }

    return -1;
  }
};

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

  Solution sol;

  int ans = sol.majorityElement(arr);

  cout << "The majority element is: " << ans << endl;

  return 0;
}

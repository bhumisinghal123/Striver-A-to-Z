/*
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSingleNumbers(vector<int> &nums)
{
  map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]]++;
  }
  vector<int> ans;
  for (auto it : mpp)
  {
    if (it.second == 1)
    {
      ans.push_back(it.first);
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3, 2, 1, 4}; // 3 and 4 are unique
  vector<int> result = twoSingleNumbers(nums);
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSingleNumbers(vector<int> &nums)
{
  long long xorr = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    xorr = xorr ^ nums[i];
  }
  int rightmost = (xorr & (xorr - 1)) ^ xorr;
  int b1 = 0;
  int b2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] & rightmost)
    {
      b1 = b1 ^ nums[i];
    }
    else
    {
      b2 = b2 ^ nums[i];
    }
  }
  return {b1, b2};
}

int main()
{
  vector<int> nums = {1, 2, 3, 2, 1, 4}; // 3 and 4 are unique
  vector<int> result = twoSingleNumbers(nums);
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
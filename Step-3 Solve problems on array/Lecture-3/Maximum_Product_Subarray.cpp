/*
#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &nums)
{
  int result = INT_MIN;
  for (int i = 0; i < nums.size() - 1; i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      int prod = 1;
      for (int k = i; k <= j; k++)
        prod *= nums[k];
      result = max(result, prod);
    }
  }
  return result;
}

int main()
{
  vector<int> nums = {1, 2, -3, 0, -4, -5};
  cout << "The maximum product subarray: " << maxProductSubArray(nums);
  return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr)
{
  int pre = 1, suff = 1;
  int ans = INT_MIN;
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    if (pre == 0)
      pre = 1;
    if (suff == 0)
      suff = 1;

    pre = pre * arr[i];
    suff = suff * arr[n - i - 1];
    ans = max(ans, max(pre, suff));
  }
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, -3, 0, -4, -5};
  cout << "The maximum product subarray: " << subarrayWithMaxProduct(nums);
  return 0;
}

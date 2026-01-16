/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {

    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i; j < nums.size(); j++)
      {
        int sum = 0;

        for (int k = i; k <= j; k++)
        {
          sum += nums[k];
        }

        maxi = max(maxi, sum);
      }
    }

    return maxi;
  }
};

int main()
{
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution sol;

  int maxSum = sol.maxSubArray(arr);

  cout << "The maximum subarray sum is: " << maxSum << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {

    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
      int sum = 0;
      for (int j = i; j < nums.size(); j++)
      {
        sum += nums[j];
        maxi = max(maxi, sum);
      }
    }

    return maxi;
  }
};

int main()
{
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution sol;

  int maxSum = sol.maxSubArray(arr);

  cout << "The maximum subarray sum is: " << maxSum << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
  long long sum = 0, maxi = LONG_MIN;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    maxi = max(maxi, sum);

    if (sum < 0)
    {
      sum = 0;
    }
  }
  return maxi;
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
  cout << maxSubarraySum(arr, n);

  return 0;
}
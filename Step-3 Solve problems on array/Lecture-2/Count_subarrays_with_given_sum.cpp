/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &arr, int k)
  {
    int n = arr.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int sum = 0;

        for (int m = i; m <= j; m++)
        {
          sum += arr[m];
        }

        if (sum == k)
        {
          count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  vector<int> arr = {3, 1, 2, 4};

  int k = 6;

  Solution sol;

  int result = sol.subarraySum(arr, k);

  cout << "The number of subarrays is: " << result << "\n";

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &arr, int k)
  {
    int n = arr.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
      int sum = 0;

      for (int j = i; j < n; j++)
      {
        sum += arr[j];

        if (sum == k)
        {
          count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  vector<int> arr = {3, 1, 2, 4};

  int k = 6;

  Solution sol;

  int result = sol.subarraySum(arr, k);

  cout << "The number of subarrays is: " << result << "\n";

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
  map<int, int> mpp;
  mpp[0] = 1;
  int preSum = 0, cnt = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    preSum += arr[i];
    int remove = preSum - k;
    cnt += mpp[remove];
    mpp[preSum] += 1;
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << findAllSubarraysWithGivenSum(arr, k);
  return 0;
}
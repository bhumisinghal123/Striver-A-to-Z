/*
#include <bits/stdc++.h>
using namespace std;

class SubarrayPartitioner
{
public:
  int countPartitions(vector<int> &a, int maxSum)
  {
    int n = a.size();
    int partitions = 1;
    long long subarraySum = 0;

    for (int i = 0; i < n; i++)
    {
      if (subarraySum + a[i] <= maxSum)
      {
        subarraySum += a[i];
      }
      else
      {
        partitions++;
        subarraySum = a[i];
      }
    }
    return partitions;
  }

  int largestSubarraySumMinimized(vector<int> &a, int k)
  {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for (int maxSum = low; maxSum <= high; maxSum++)
    {
      if (countPartitions(a, maxSum) == k)
        return maxSum;
    }
    return low;
  }
};

int main()
{
  vector<int> a = {10, 20, 30, 40};
  int k = 2;
  SubarrayPartitioner sp;
  int ans = sp.largestSubarraySumMinimized(a, k);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
  int students = 1;
  long long pagesStudent = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (pagesStudent + arr[i] <= pages)
    {
      pagesStudent += arr[i];
    }
    else
    {
      students += 1;
      pagesStudent = arr[i];
    }
  }
  return students;
}

int findPages(vector<int> &arr, int n, int m)
{
  if (m > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int students = countStudents(arr, mid);
    if (students > m)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

int largestSubarraySumMinimized(vector<int> a, int k)
{
  return findPages(a, a.size(), k);
}

int main()
{
  vector<int> arr = {25, 46, 28, 49, 24};
  int m = 2;
  int ans = largestSubarraySumMinimized(arr, m);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
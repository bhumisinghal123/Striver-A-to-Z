/*
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;


    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{

  int left = n - 1;
  int right = 0;

  while (left >= 0 && right < m)
  {
    if (arr1[left] > arr2[right])
    {
      swap(arr1[left], arr2[right]);
      left--, right++;
    }
    else
    {
      break;
    }
  }

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

int main()
{
  long long arr1[] = {1, 4, 8, 10};
  long long arr2[] = {2, 3, 9};
  int n = 4, m = 3;
  merge(arr1, arr2, n, m);
  cout << "The merged arrays are: " << "\n";
  cout << "arr1[] = ";
  for (int i = 0; i < n; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << "\narr2[] = ";
  for (int i = 0; i < m; i++)
  {
    cout << arr2[i] << " ";
  }
  cout << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1;

    int j = n - 1;

    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
      if (nums1[i] > nums2[j])
      {
        nums1[k--] = nums1[i--];
      }
      else
      {
        nums1[k--] = nums2[j--];
      }
    }

    while (j >= 0)
    {
      nums1[k--] = nums2[j--];
    }
  }
};

int main()
{
  vector<int> nums1 = {1, 3, 5, 0, 0, 0};
  vector<int> nums2 = {2, 4, 6};
  int m = 3, n = 3;

  Solution().merge(nums1, m, nums2, n);

  for (int num : nums1)
    cout << num << " ";
  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
  vector<int> arr3;

  int i = 0, j = 0;
  while (i < m && j < n)
  {
    if (a[i] < b[j])
      arr3.push_back(a[i++]);
    else
      arr3.push_back(b[j++]);
  }

  while (i < m)
    arr3.push_back(a[i++]);
  while (j < n)
    arr3.push_back(b[j++]);
  return arr3[k - 1];
}

int main()
{
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
  int ele = -1;
  int cnt = 0;
  int i = 0, j = 0;
  while (i < m && j < n)
  {
    if (a[i] < b[j])
    {
      if (cnt == k - 1)
        ele = a[i];
      cnt++;
      i++;
    }
    else
    {
      if (cnt == k - 1)
        ele = b[j];
      cnt++;
      j++;
    }
  }

  while (i < m)
  {
    if (cnt == k - 1)
      ele = a[i];
    cnt++;
    i++;
  }
  while (j < n)
  {
    if (cnt == k - 1)
      ele = b[j];
    cnt++;
    j++;
  }
  return ele;
}

int main()
{
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{
  if (n1 > n2)
    return kthElement(b, a, n2, n1, k);
  int low = max(k - n2, 0), high = min(k, n1);
  int left = k;
  int n = n1 + n2;
  while (low <= high)
  {
    int mid1 = (low + high) >> 1;
    int mid2 = left - mid1;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n1)
      r1 = a[mid1];
    if (mid2 < n2)
      r2 = b[mid2];
    if (mid1 - 1 >= 0)
      l1 = a[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = b[mid2 - 1];
    if (l1 <= r2 && l2 <= r1)
    {
      return max(l1, l2);
    }
    else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
}

int main()
{
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr, int n)
{
  if (n == 1)
    return arr[0];

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (arr[i] != arr[i + 1])
        return arr[i];
    }
    else if (i == n - 1)
    {
      if (arr[i] != arr[i - 1])
        return arr[i];
    }
    else
    {
      if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        return arr[i];
    }
  }
  return -1;
}
int main()
{
  vector<int> a = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6};
  int n = 11;
  int ans = singleElement(a, n);
  cout << "The single element is " << ans << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
  int n = arr.size(); // size of the array.
  int ans = 0;
  // XOR all the elements:
  for (int i = 0; i < n; i++)
  {
    ans = ans ^ arr[i];
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
  int ans = singleNonDuplicate(arr);
  cout << "The single element is: " << ans << "\n";
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr, int n)
{
  if (n == 1)
    return arr[0];
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];
  int low = 1, high = n - 2;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
    {
      return arr[mid];
    }

    if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  vector<int> a = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6};
  int n = 11;
  int ans = singleElement(a, n);
  cout << "The single element is " << ans << endl;
  return 0;
}
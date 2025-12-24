/*
#include <bits/stdc++.h>
using namespace std;

int sortArr(vector<int> &arr)
{
  sort(arr.begin(), arr.end());

  return arr[arr.size() - 1];
}

int main()
{
  vector<int> arr1 = {2, 5, 1, 3, 0};

  cout << "The Largest element in the array is: " << sortArr(arr1) << endl;

  return 0;
}
  */

#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n)
{
  int largest = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
    {
      largest = arr[i];
    }
  }
  return largest;
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
  cout << largestElement(arr, n) << endl;
  return 0;
}

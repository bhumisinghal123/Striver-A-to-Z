#include <bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (arr[i] != arr[j])
    {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  return i + 1;
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
  int newSize = removeDuplicate(arr, n);
  for (int k = 0; k < newSize; k++)
  {
    cout << arr[k] << " ";
  }
  cout << endl;

  return 0;
}
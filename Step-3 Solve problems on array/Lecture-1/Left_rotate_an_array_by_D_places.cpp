#include <bits/stdc++.h>
using namespace std;

// Brute solution
/* void leftRotate(int arr[], int n, int d)
{
  d = d % n;

  int temp[d];
  for (int i = 0; i < d; i++)
  {
    temp[i] = arr[i];
  }

  for (int i = d; i < n; i++)
  {
    arr[i - d] = arr[i];
  }

  for (int i = n - d; i < n; i++)
  {
    arr[i] = temp[i - (n - d)];
  }
} */

// if reverse function is not available
/* void Reevrse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
} */

// Optimal solution
void leftRotate(int arr[], int n, int d)
{
  reverse(arr, arr + d);
  reverse(arr + d, arr + n);
  reverse(arr, arr + n);
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

  int d;
  cin >> d;
  leftRotate(arr, n, d);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
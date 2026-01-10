#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);

  return i + 1;
}

void qs(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pIndex = partition(arr, low, high);
    qs(arr, low, pIndex - 1);
    qs(arr, pIndex + 1, high);
  }
}
vector<int> quickSort(vector<int> arr)
{
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  arr = quickSort(arr);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
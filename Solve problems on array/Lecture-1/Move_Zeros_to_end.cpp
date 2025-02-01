#include <bits/stdc++.h>
using namespace std;

// Brute solution
int moveZero(int n, int arr[])
{
  vector<int> temp;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      temp.push_back(arr[i]);
    }
  }

  int nz = temp.size();
  for (int i = 0; i < nz; i++)
  {
    arr[i] = temp[i];
  }
  for (int i = nz; i < n; i++)
  {
    arr[i] = 0;
  }
}

// Optimal solution
/* int moveZero(int arr[], int n)
{
  int j = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}
*/

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  moveZero(n, arr);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
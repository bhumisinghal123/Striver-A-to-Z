#include <bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
  /*
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    int a = book[i];
    int more = target - a;
    if (mpp.find(more) != mpp.end())
    {
      return "YES";
    }
    mpp[a] = i;
  }
  return "NO";
  */

  int left = 0, right = n - 1;
  sort(book.begin(), book.end());
  while (left < right)
  {
    int sum = book[left] + book[right];
    if (sum == target)
    {
      return "YES";
    }
    else if (sum < target)
      left++;
    else
      right--;
  }
  return "NO";
}

int main()
{
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << read(n, arr, k);
  return 0;
}
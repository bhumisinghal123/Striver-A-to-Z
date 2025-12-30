#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> a = {9, 8, 6, 7, 0, -1, 8};
  int n = a.size();
  vector<int> b(n, 0);

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      b[i] = a[i] + a[i + 1];
    }
    else if (i == n - 1)
    {
      b[i] = a[i - 1] + a[i];
    }
    else
    {
      b[i] = a[i - 1] + a[i] + a[i + 1];
    }
    cout << b[i] << " ";
  }

  return 0;
}
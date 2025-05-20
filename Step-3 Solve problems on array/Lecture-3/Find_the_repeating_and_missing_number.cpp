#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
  /*
  int n = a.size();
  int hash[n + 1] = {0};
  for (int i = 0; i < n; i++)
  {
    hash[a[i]]++;
  }
  int repeating = -1, missing = -1;
  for (int i = 1; i <= n; i++)
  {
    if (hash[i] == 2)
      repeating = i;
    else if (hash[i] == 0)
      missing = i;

    if (repeating != -1 && missing != -1)
    {
      break;
    }
  }
  return {repeating, missing};
  */

  /*
  long long n = a.size();
  // S - Sn = x - y
  //  S2 - S2N
  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
  long long S = 0, S2 = 0;
  for (int i = 0; i < n; i++)
  {
    S += a[i];
    S2 += (long long)a[i] * (long long)a[i];
  }
  long long val1 = S - SN; // x - y
  long long val2 = S2 - S2N;
  val2 = val2 / val1; // x + y
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
  */

  long long n = a.size();
  int xr = 0;
  for (int i = 0; i < n; i++)
  {
    xr = xr ^ a[i];
    xr = xr ^ (i + 1);
  }
  int bitNo = 0;
  while (1)
  {
    if ((xr & (1 << bitNo)) != 0)
    {
      break;
    }
    bitNo++;
  }
  int zero = 0;
  int one = 0;
  for (int i = 0; i < n; i++)
  {
    // part of 1 club
    if ((a[i] & (1 << bitNo)) != 0)
    {
      one = one ^ a[i];
    }
    // zeroth club
    else
    {
      zero = one ^ a[i];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    // part of 1 club
    if ((i & (1 << bitNo)) != 0)
    {
      one = one ^ i;
    }
    // zeroth club
    else
    {
      zero = one ^ i;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == zero)
      cnt++;
  }
  if (cnt == 2)
    return {zero, one};
  return {one, zero};
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
  vector<int> result = findMissingRepeatingNumbers(arr);
  for (int num : result)
  {
    cout << num << " ";
  }

  return 0;
}
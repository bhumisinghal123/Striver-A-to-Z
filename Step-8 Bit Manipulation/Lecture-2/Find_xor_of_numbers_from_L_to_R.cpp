/*
#include <bits/stdc++.h>
using namespace std;

int xorOfNumber(int n)
{
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = ans ^ i;
  }
  return ans;
}

int main()
{
  int n = 4;
  int ans = xorOfNumber(n);
  cout << ans;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int xorOfNumber(int n)
{
  if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  else if (n % 4 == 3)
    return 0;
  else
    return n;
}

int main()
{
  int n = 4;
  int ans = xorOfNumber(n);
  cout << ans;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int xorOfNumber(int n)
{
  if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  else if (n % 4 == 3)
    return 0;
  else
    return n;
}

int xorBetween2Numbers(int n, int m)
{
  return xorOfNumber(n - 1) ^ xorOfNumber(m);
}

int main()
{
  int n = 4;
  int m = 7;
  int ans = xorBetween2Numbers(n, m);
  cout << ans;
  return 0;
}
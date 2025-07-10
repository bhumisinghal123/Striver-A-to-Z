#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
  long long nn = n;
  double ans = 1.0;
  if (nn < 0)
    nn = -1LL * nn;

  while (nn > 0)
  {
    if (nn % 2 == 1)
    {
      ans *= x;
      nn--;
    }
    else
    {
      x *= x;
      nn /= 2;
    }
  }

  if (n < 0)
    return 1.0 / ans;

  return ans;
}

int main()
{
  double x;
  int n;
  cin >> x >> n;
  cout << myPow(x, n) << endl;
  return 0;
}

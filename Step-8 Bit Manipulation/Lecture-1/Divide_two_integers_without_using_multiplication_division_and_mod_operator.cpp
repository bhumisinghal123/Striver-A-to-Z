/*
#include <bits/stdc++.h>
using namespace std;

int divide2Numbers(int divisor, int dividend)
{
  int sum = 0;
  int cnt = 0;
  while (sum + divisor <= dividend)
  {
    cnt++;
    sum += divisor;
  }
  return cnt;
}

int main()
{
  int divisor = 3;
  int dividend = 22;
  int ans = divide2Numbers(divisor, dividend);
  cout << ans;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
  if (dividend == divisor)
    return 1;

  bool sign = true;
  if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    sign = false;

  long long n = abs(static_cast<long long>(dividend));
  long long d = abs(static_cast<long long>(divisor));
  long long ans = 0;

  while (n >= d)
  {
    int count = 0;
    while (n >= (d << (count + 1)))
      count++;
    ans += (1LL << count);
    n -= (d << count);
  }

  if (ans > INT_MAX)
    return sign ? INT_MAX : INT_MIN;

  return sign ? static_cast<int>(ans) : -static_cast<int>(ans);
}

int main()
{
  int dividend = -10, divisor = 3;
  cout << divide(dividend, divisor) << endl; // Output: -3
  return 0;
}

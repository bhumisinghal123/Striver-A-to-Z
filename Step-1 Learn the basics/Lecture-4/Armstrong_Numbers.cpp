#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  int dup = n;
  int cnt = (int)(log10(n) + 1);
  while (n > 0)
  {
    int lastDigit = n % 10;
    sum = sum + pow(lastDigit, cnt);
    n = n / 10;
  }
  if (sum == dup)
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  return 0;
}
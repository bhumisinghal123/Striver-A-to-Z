#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n)
{
  int revNum = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    n = n / 10;
    revNum = (revNum * 10) + lastDigit;
  }
  return revNum;
}

int main()
{
  int n;
  cin >> n;
  cout << reverseNumber(n);
  return 0;
}
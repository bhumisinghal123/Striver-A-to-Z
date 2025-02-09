#include <bits/stdc++.h>
using namespace std;

// void printSum(int i, int sum)
// {
//   if (i < 1)
//   {
//     cout << sum;
//     return;
//   }
//   printSum(i - 1, sum + i);
// }

// int main()
// {
//   int n;
//   cin >> n;
//   printSum(n, 0);
//   return 0;
// }

int sum(int n)
{
  if (n == 0)
    return 0;
  return n + sum(n - 1);
}

int main()
{
  int n;
  cin >> n;
  cout << sum(n);
}
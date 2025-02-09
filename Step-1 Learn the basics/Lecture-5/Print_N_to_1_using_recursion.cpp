#include <bits/stdc++.h>
using namespace std;

// void printRevNumber(int n)
// {
//   if (n < 1)
//   {
//     return;
//   }
//   cout << n << endl;
//   printRevNumber(n - 1);
// }

// int main()
// {
//   int n;
//   cin >> n;
//   printRevNumber(n);
//   return 0;
// }

void printRevNumber(int i, int n)
{
  if (i > n)
  {
    return;
  }
  printRevNumber(i + 1, n);
  cout << i << endl;
}

int main()
{
  int n;
  cin >> n;
  printRevNumber(1, n);
  return 0;
}
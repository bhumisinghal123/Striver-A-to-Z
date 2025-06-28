// Decimal to binary conversion
/*
#include <bits/stdc++.h>
using namespace std;

string convert2Binary(int x)
{
  if (x == 0)
    return "0";

  string res = "";
  while (x != 1)
  {
    if (x % 2 == 1)
      res += '1';
    else
      res += '0';

    x = x / 2;
  }

  res += '1';
  reverse(res.begin(), res.end());
  return res;
}


int main()
{
  int number;
  cout << "Enter a decimal number: ";
  cin >> number;

  string binary = convert2Binary(number);
  cout << "Binary: " << binary << endl;
  return 0;
}
*/

// Binary to decimal conversion
/*
#include <bits/stdc++.h>
using namespace std;

int convert2Decimal(string x)
{
  int len = x.length();
  int p2 = 1;
  int num = 0;
  for (int i = len - 1; i >= 0; i--)
  {
    if (x[i] == '1')
      num = num + p2;
    p2 = p2 * 2;
  }
  return num;
}

int main()
{
  string n;
  cout << "Enter a binary number: ";
  cin >> n;

  int decimal = convert2Decimal(n);
  cout << "Decimal: " << decimal << endl;
  return 0;
}
*/
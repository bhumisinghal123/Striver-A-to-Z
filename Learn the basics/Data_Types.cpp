// int, long, long long, float, double
// string, getline
// char
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  cin >> str;

  if (str == "Character")
  {
    cout << sizeof(char);
  }
  else if (str == "Integer")
  {
    cout << sizeof(int);
  }
  else if (str == "Long")
  {
    cout << sizeof(long);
  }
  else if (str == "Float")
  {
    cout << sizeof(float);
  }
  else if (str == "Double")
  {
    cout << sizeof(double);
  }
  else
  {
    cout << "Invalid choice";
  }
  return 0;
}
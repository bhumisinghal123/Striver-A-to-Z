// int, long, long long, float, double
// string, getline
// char
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dataTypeSize(string str)
  {
    if (str == "Character")
    {
      return sizeof(char);
    }
    else if (str == "Integer")
    {
      return sizeof(int);
    }
    else if (str == "Long")
    {
      return sizeof(long);
    }
    else if (str == "Float")
    {
      return sizeof(float);
    }
    else if (str == "Double")
    {
      return sizeof(double);
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  string str;
  cin >> str;
  Solution obj;
  cout << obj.dataTypeSize(str);
  return 0;
}
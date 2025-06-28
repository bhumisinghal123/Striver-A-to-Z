#include <iostream>
using namespace std;

bool isPowerOfTwo(int num)
{
  if (num <= 0)
    return false;
  return (num & (num - 1)) == 0;
}

int main()
{
  int num;
  cout << "Enter a number: ";
  cin >> num;

  if (isPowerOfTwo(num))
  {
    cout << num << " is a Power of 2" << endl;
  }
  else
  {
    cout << num << " is NOT a Power of 2" << endl;
  }

  return 0;
}

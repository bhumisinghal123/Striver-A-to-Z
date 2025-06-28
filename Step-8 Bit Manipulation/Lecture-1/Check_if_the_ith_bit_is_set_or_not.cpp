#include <iostream>
using namespace std;

bool isBitSet(int num, int i)
{
  return (num & (1 << i)) != 0;
}

int main()
{
  int number, bitIndex;

  cout << "Enter a number: ";
  cin >> number;

  cout << "Enter the bit index to check (0-based): ";
  cin >> bitIndex;

  if (isBitSet(number, bitIndex))
    cout << "The " << bitIndex << "-th bit is SET (1)." << endl;
  else
    cout << "The " << bitIndex << "-th bit is NOT set (0)." << endl;

  return 0;
}

// 5)	Toggle the i’th bit : Num=(Num^(1<<i));

// 6)	Remove the last set bit (RightMost) : Num=(Num&(Num-1));

// 9)	Divide a number by 2 : Num=(Num>>1);

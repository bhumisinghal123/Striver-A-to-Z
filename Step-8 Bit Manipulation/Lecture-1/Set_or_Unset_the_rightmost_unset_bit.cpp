#include <iostream>
using namespace std;
int setIthBit(int num, int i)
{
  return (num | (1 << i));
}

int unsetIthBit(int num, int i)
{
  return (num & ~(1 << i));
}

int main()
{
  int number, bitIndex;

  cout << "Enter a number: ";
  cin >> number;

  cout << "Enter the bit index (0-based) to modify: ";
  cin >> bitIndex;

  int afterSet = setIthBit(number, bitIndex);
  int afterUnset = unsetIthBit(number, bitIndex);

  cout << "Original number      : " << number << endl;
  cout << "After setting bit " << bitIndex << " : " << afterSet << endl;
  cout << "After unsetting bit " << bitIndex << " : " << afterUnset << endl;

  return 0;
}

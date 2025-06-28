#include <iostream>
using namespace std;

int countSetBits(int num)
{
  int count = 0;
  while (num != 0)
  {
    num = num & (num - 1);
    count++;
  }
  return count;
}

int main()
{
  int number;
  cout << "Enter a number: ";
  cin >> number;

  int result = countSetBits(number);
  cout << "Number of set bits in " << number << " is: " << result << endl;

  return 0;
}

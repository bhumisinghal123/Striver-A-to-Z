#include <iostream>
using namespace std;

bool isOdd(int num)
{
  return (num & 1);
}

int main()
{
  int number;
  cout << "Enter a number: ";
  cin >> number;

  if (isOdd(number))
    cout << number << " is an ODD number." << endl;
  else
    cout << number << " is an EVEN number." << endl;

  return 0;
}

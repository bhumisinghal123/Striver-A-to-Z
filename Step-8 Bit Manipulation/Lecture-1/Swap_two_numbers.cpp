#include <iostream>
using namespace std;

int main()
{
  int num1, num2;

  cout << "Enter first number (num1): ";
  cin >> num1;

  cout << "Enter second number (num2): ";
  cin >> num2;

  cout << "\nBefore swapping:" << endl;
  cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

  num1 = num1 ^ num2;
  num2 = num1 ^ num2;
  num1 = num1 ^ num2;

  cout << "\nAfter swapping:" << endl;
  cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

  return 0;
}

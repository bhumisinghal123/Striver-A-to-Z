#include <iostream>
using namespace std;

int countBitsToConvert(int start, int goal)
{
  int num = start ^ goal;
  int cnt = 0;

  while (num > 0)
  {
    cnt += (num & 1);
    num = num >> 1;
  }

  return cnt;
}

int main()
{
  int start, goal;

  cout << "Enter the start number: ";
  cin >> start;

  cout << "Enter the goal number: ";
  cin >> goal;

  int differingBits = countBitsToConvert(start, goal);

  cout << "Number of differing bits between " << start << " and " << goal << " is: " << differingBits << endl;

  return 0;
}

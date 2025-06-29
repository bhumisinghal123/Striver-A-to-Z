#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {1, 3, 1, 2, 3};
  int xorr = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    xorr ^= nums[i];
  }
  cout << "Resulting XOR: " << xorr << endl;
  return 0;
}

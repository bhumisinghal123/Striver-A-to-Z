/*
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
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> nums = {1, 3, 1, 2, 3, 3, 1};
  int ans = 0;
  for (int bitIndex = 0; bitIndex <= 31; bitIndex++)
  {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if ((nums[i] & (1 << bitIndex)))
      {
        cnt++;
      }
    }
    if (cnt % 3 == 1)
    {
      ans = (ans | (1 << bitIndex));
    }
  }
  cout << ans << endl;
  return 0;
};
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> nums = {1, 2, 3};
  int n = nums.size();
  int subsets = 1 << n; // 2^n subsets

  vector<vector<int>> al;

  for (int i = 0; i < subsets; i++)
  {
    vector<int> subal;
    for (int j = 0; j < n; j++)
    {
      if ((i & (1 << j)) != 0)
      {
        subal.push_back(nums[j]);
      }
    }
    al.push_back(subal);
  }

  // Print all subsets
  for (const auto &subset : al)
  {
    cout << "[";
    for (int k = 0; k < subset.size(); k++)
    {
      cout << subset[k];
      if (k < subset.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}

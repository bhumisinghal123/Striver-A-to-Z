#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> previousSmallestElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && st.top() >= nums[i])
      {
        st.pop();
      }
      pse[i] = st.empty() ? -1 : st.top();
      st.push(nums[i]);
    }
    return pse;
  }
};
int main()
{
  Solution obj;
  vector<int> v{5, 7, 1, 2, 6, 0};
  vector<int> res = obj.previousSmallestElements(v);
  cout << "The previous smaller elements are" << endl;
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}
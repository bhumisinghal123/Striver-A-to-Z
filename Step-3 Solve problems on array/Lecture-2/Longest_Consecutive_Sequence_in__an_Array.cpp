#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &nums)
{
  /*
  if (nums.size() == 0)
    return 0;
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int lastSmaller = INT_MIN;
  int cnt = 0;
  int longest = 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] - 1 == lastSmaller)
    {
      cnt += 1;
      lastSmaller = nums[i];
    }
    else if (lastSmaller != nums[i])
    {
      cnt = 1;
      lastSmaller = nums[i];
    }
    longest = max(longest, cnt);
  }
  return longest;
*/

  int n = nums.size();
  if (n == 0)
    return 0;
  int longest = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(nums[i]);
  }

  for (auto it : st)
  {
    if (st.find(it - 1) == st.end())
    {
      int cnt = 1;
      int x = it;
      while (st.find(x + 1) != st.end())
      {
        x = x + 1;
        cnt = cnt + 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << longestSuccessiveElements(arr);
  return 0;
}
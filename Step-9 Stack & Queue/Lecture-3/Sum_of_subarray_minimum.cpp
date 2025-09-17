/*
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int sumSubarrayMins(vector<int> &arr)
{
  long long sum = 0;
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    int mini = arr[i];
    for (int j = i; j < n; j++)
    {
      mini = min(mini, arr[j]);
      sum = (sum + mini) % mod;
    }
  }
  return (int)sum;
}

int main()
{
  vector<int> arr = {3, 1, 2, 6, 5};
  cout << sumSubarrayMins(arr);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> nse(n), pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
      {
        st.pop();
      }
      pse[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
        st.pop();
      }
      nse[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    long long total = 0;
    long long mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
      long long left = i - pse[i];
      long long right = nse[i] - i;
      total = (total + (right * left % mod * arr[i] % mod) % mod) % mod;
    }

    return (int)total;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {3, 1, 2, 4};
  cout << sol.sumSubarrayMins(arr) << endl;
  return 0;
}

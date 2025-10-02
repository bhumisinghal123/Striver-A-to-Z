/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> stockSpan(vector<int> arr, int n)
  {
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
      int currSpan = 0;
      for (int j = i; j >= 0; j--)
      {
        if (arr[j] <= arr[i])
        {
          currSpan++;
        }
        else
          break;
      }
      ans[i] = currSpan;
    }
    return ans;
  }
};

int main()
{
  int n = 7;
  vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
  Solution sol;
  vector<int> ans = sol.stockSpan(arr, n);
  cout << "The span of stock prices is: ";
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
  */

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
  stack<pair<int, int>> st;

public:
  StockSpanner() {}

  int next(int price)
  {
    int span = 1;
    while (!st.empty() && st.top().first <= price)
    {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};

int main()
{
  StockSpanner *obj = new StockSpanner();
  cout << obj->next(100) << " ";
  cout << obj->next(80) << " ";
  cout << obj->next(60) << " ";
  cout << obj->next(70) << " ";
  cout << obj->next(60) << " ";
  cout << obj->next(75) << " ";
  cout << obj->next(85) << " ";
}

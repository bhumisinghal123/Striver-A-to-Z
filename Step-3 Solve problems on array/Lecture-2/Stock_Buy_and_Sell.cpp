/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int stockbuySell(vector<int> &prices)
  {
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
      for (int j = i + 1; j < prices.size(); j++)
      {
        int profit = prices[j] - prices[i];
        maxProfit = max(maxProfit, profit);
      }
    }

    return maxProfit;
  }
};

int main()
{
  Solution sol;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << "Max Profit: " << sol.stockbuySell(prices) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
  int mini = prices[0];
  int maxProfit = 0;
  int n = prices.size();
  for (int i = 0; i < n; i++)
  {
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }
  return maxProfit;
}

int main()
{
  int n;
  cin >> n;
  vector<int> prices(n);

  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }

  cout << maximumProfit(prices) << endl;
  return 0;
}
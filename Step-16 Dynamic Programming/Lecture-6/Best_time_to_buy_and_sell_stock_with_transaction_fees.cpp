#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int> &prices)
{
    int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        curNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);

        curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}
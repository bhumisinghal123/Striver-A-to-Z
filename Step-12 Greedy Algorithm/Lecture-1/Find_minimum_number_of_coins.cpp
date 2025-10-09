#include <bits/stdc++.h>
using namespace std;

void findMinCoins(int V)
{
  int demo[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
  int n = 9;
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
  {
    while (V >= demo[i])
    {
      V -= demo[i];
      ans.push_back(demo[i]);
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  int V = 43;
  findMinCoins(V);
  return 0;
}
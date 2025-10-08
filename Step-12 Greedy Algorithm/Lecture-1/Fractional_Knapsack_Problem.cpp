#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int value;
  int weight;
};

class Solution
{
public:
  bool static comp(Item a, Item b)
  {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
  }

  double fractionalKnapsack(int W, Item arr[], int n)
  {
    sort(arr, arr + n, comp);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
      if (curWeight + arr[i].weight <= W)
      {
        curWeight += arr[i].weight;
        finalValue += arr[i].value;
      }
      else
      {
        int remain = W - curWeight;
        finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
        break;
      }
    }
    return finalValue;
  }
};

int main()
{
  int W = 50;
  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(arr) / sizeof(arr[0]);
  Solution sol;
  cout << "Maximum value in Knapsack = " << sol.fractionalKnapsack(W, arr, n) << endl;
  return 0;
}
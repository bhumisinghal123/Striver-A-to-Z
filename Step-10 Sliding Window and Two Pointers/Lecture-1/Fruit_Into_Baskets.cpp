/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int maxFruits = 0;
    for (int start = 0; start < fruits.size(); start++)
    {
      unordered_map<int, int> basket;
      int currentCount = 0;
      for (int end = start; end < fruits.size(); ++end)
      {
        basket[fruits[end]]++;
        if (basket.size() > 2)
        {
          break;
        }
        currentCount++;
      }
      maxFruits = max(maxFruits, currentCount);
    }
    return maxFruits;
  }
};

int main()
{
  Solution sol;
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  cout << sol.totalFruit(fruits) << endl;
  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    unordered_map<int, int> basket;
    int maxFruits = 0;
    int left = 0;
    for (int right = 0; right < fruits.size(); right++)
    {
      basket[fruits[right]]++;
      while (basket.size() > 2)
      {
        basket[fruits[left]]--;

        if (basket[fruits[left]] == 0)
        {
          basket.erase(fruits[left]);
        }
        left++;
      }
      maxFruits = max(maxFruits, right - left + 1);
    }
    return maxFruits;
  }
};

int main()
{
  Solution sol;
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  cout << sol.totalFruit(fruits) << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalFruits(vector<int> &fruits)
  {
    int maxlen = 0;
    int lastFruit = -1;
    int secondlastFruit = -1;
    int currcount = 0;
    int lastFruitstreak = 0;

    for (int fruit : fruits)
    {
      if (fruit == lastFruit || fruit == secondlastFruit)
      {
        currcount++;
      }
      else
      {
        currcount = lastFruitstreak + 1;
      }

      if (fruit == lastFruit)
      {
        lastFruitstreak++;
      }
      else
      {
        lastFruitstreak = 1;
        secondlastFruit = lastFruit;
        lastFruit = fruit;
      }
      maxlen = max(maxlen, currcount);
    }
    return maxlen;
  }
};

int main()
{
  Solution sol;
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  cout << sol.totalFruits(fruits) << endl;
  return 0;
}
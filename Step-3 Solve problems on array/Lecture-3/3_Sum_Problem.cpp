#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &num)
{
  /*
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          if (num[i] + num[j] + num[k] == 0)
          {
            vector<int> temp = {num[i],
                                num[j],
                                num[k]};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    */
  /*
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
      set<int> hashset;
      for (int j = i + 1; j < n; j++)
      {
        int third = -(num[i] + num[j]);
        if (hashset.find(third) != hashset.end())
        {
          vector<int> temp = {num[i], num[j], third};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(num[j]);
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    */

  vector<vector<int>> ans;
  sort(num.begin(), num.end());
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && num[i] == num[i - 1])
      continue;
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      int sum = num[i] + num[j] + num[k];
      if (sum < 0)
      {
        j++;
      }
      else if (sum > 0)
      {
        k--;
      }
      else
      {
        vector<int> temp = {num[i], num[j], num[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && num[j] == num[j - 1])
          j++;
        while (j < k && num[k] == num[k + 1])
          k--;
      }
    }
  }
  return ans;
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
  vector<vector<int>> result = triplet(n, arr);
  for (auto triplet : result)
  {
    for (int num : triplet)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
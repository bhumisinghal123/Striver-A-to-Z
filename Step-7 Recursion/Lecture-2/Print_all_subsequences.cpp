#include <bits/stdc++.h>
using namespace std;

/*
vector<string> AllPossibleStrings(string s)
{
  int n = s.length();
  vector<string> ans;
  for (int num = 0; num < (1 << n); num++)
  {
    string sub = "";
    for (int i = 0; i < n; i++)
    {
      if (num & (1 << i))
      {
        sub += s[i];
      }
    }
    if (sub.length() > 0)
    {
      ans.push_back(sub);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}
int main()
{

  string s = "abc";
  vector<string> ans = AllPossibleStrings(s);
  cout << "All possible subsequences are " << endl;
  for (auto it : ans)
  {
    cout << it << " ";
  }
}
*/

void printF(int ind, vector<int> &ds, int arr[], int n)
{
  if (ind == n)
  {
    for (auto it : ds)
    {
      cout << it << " ";
    }
    if (ds.size() == 0)
    {
      cout << "{}";
    }
    cout << endl;
    return;
  }
  ds.push_back(arr[ind]);
  printF(ind + 1, ds, arr, n);
  ds.pop_back();
  printF(ind + 1, ds, arr, n);
}

int main()
{
  int arr[] = {3, 1, 2};
  int n = 3;
  vector<int> ds;
  printF(0, ds, arr, n);
}
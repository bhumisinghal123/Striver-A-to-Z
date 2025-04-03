#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
  vector<int> ans;
  int maxi = INT_MIN;
  int n = a.size();
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] > maxi)
    {
      ans.push_back(a[i]);
    }
    maxi = max(maxi, a[i]);
  }

  sort(ans.begin(), ans.end());
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
  vector<int> result = superiorElements(arr);
  for (int i = 0; i < n; i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}
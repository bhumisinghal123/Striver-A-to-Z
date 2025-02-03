#include <bits/stdc++.h>
using namespace std;

// Brute solution
/* vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
  vector<int> ans;
  int vis[m] = {0};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i] == b[j] && vis[j] == 0)
      {
        ans.push_back(a[i]);
        vis[j] = 1;
        break;
      }
      if (b[j] > a[i])
        break;
    }
  }
  return ans;
}
*/

// Optimal solution
vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n && j < m)
  {
    if (a[i] < b[j])
    {
      i++;
    }
    else if (b[j] < a[i])
    {
      j++;
    }
    else
    {
      ans.push_back(a[i]);
      i++;
      j++;
    }
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  vector<int> intersectedArray = findArrayIntersection(a, n, b, m);
  for (int num : intersectedArray)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}

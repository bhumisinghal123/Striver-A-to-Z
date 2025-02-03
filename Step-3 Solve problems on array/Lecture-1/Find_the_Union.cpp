#include <bits/stdc++.h>
using namespace std;

// Brute solution
/* vector<int> sortedArray(vector<int> a, vector<int> b)
{
  int n1 = a.size();
  int n2 = b.size();
  set<int> st;
  for (int i = 0; i < n1; i++)
  {
    st.insert(a[i]);
  }
  for (int i = 0; i < n2; i++)
  {
    st.insert(b[i]);
  }
  vector<int> temp;
  for (auto it : st)
  {
    temp.push_back(it);
  }
  return temp;
} */

// Optimal solution
vector<int> sortedArray(vector<int> a, vector<int> b)
{
  int n1 = a.size();
  int n2 = b.size();
  int i = 0;
  int j = 0;
  vector<int> unionArr;
  while (i < n1 && j < n2)
  {
    if (a[i] <= b[j])
    {
      if (unionArr.size() == 0 || unionArr.back() != a[i])
      {
        unionArr.push_back(a[i]);
      }
      i++;
    }
    else
    {
      if (unionArr.size() == 0 || unionArr.back() != b[j])
      {
        unionArr.push_back(b[j]);
      }
      j++;
    }
  }

  while (j < n2)
  {
    if (unionArr.size() == 0 || unionArr.back() != b[j])
    {
      unionArr.push_back(b[j]);
    }
    j++;
  }

  while (i < n1)
  {
    if (unionArr.size() == 0 || unionArr.back() != a[i])
    {
      unionArr.push_back(a[i]);
    }
    i++;
  }
  return unionArr;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> a(n1), b(n2);
  for (int i = 0; i < n1; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n2; i++)
  {
    cin >> b[i];
  }

  vector<int> mergedArray = sortedArray(a, b);
  for (int num : mergedArray)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
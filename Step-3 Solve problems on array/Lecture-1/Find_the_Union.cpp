/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
  {
    map<int, int> freq;
    vector<int> Union;
    for (int i = 0; i < n; i++)
      freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
      freq[arr2[i]]++;
    for (auto &it : freq)
      Union.push_back(it.first);
    return Union;
  }
};

int main()
{
  int n = 10;
  int m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  Solution obj;
  vector<int> Union = obj.FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto &val : Union)
    cout << val << " ";
  return 0;
}
*/

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

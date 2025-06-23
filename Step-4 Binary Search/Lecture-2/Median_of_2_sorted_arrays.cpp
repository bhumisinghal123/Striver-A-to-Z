/*
#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
  vector<int> arr3;
  int n1 = a.size(), n2 = b.size();
  int i = 0;
  int j = 0;
  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
      arr3.push_back(a[i++]);
    else
      arr3.push_back(b[j++]);
  }
  while (i < n1)
    arr3.push_back(a[i++]);
  while (j < n2)
    arr3.push_back(a[j++]);
  int n = (n1 + n2);
  if (n % 2 == 1)
  {
    return arr3[n / 2];
  }
  return (double)((double)(arr3[n / 2]) + (double)(arr3[n / 2 - 1])) / 2.0;
}

int main()
{
  vector<int> a = {1, 4, 7, 10, 12};
  vector<int> b = {2, 3, 6, 15};
  cout << "The median of two sorted array is " << fixed << setprecision(1)
       << median(a, b) << '\n';
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

double median(vector<int> &a, vector<int> &b)
{
  int n1 = a.size(), n2 = b.size();
  int i = 0;
  int j = 0;
  int n = (n1 + n2);
  int ind2 = n / 2;
  int ind1 = ind2 - 1;
  int cnt = 0;
  int ind1el = -1, ind2el = -1;
  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
    {
      if (cnt == ind1)
        ind1el = a[i];
      if (cnt == ind2)
        ind2el = a[i];
      cnt++;
      i++;
    }
    else
    {
      if (cnt == ind1)
        ind1el = b[j];
      if (cnt == ind2)
        ind2el = b[j];
      cnt++;
      j++;
    }
  }
  while (i < n1)
  {
    if (cnt == ind1)
      ind1el = a[i];
    if (cnt == ind2)
      ind2el = a[i];
    cnt++;
    i++;
  }
  while (j < n2)
  {
    if (cnt == ind1)
      ind1el = b[i];
    if (cnt == ind2)
      ind2el = b[i];
    cnt++;
    j++;
  }
  if (n % 2 == 1)
  {
    return ind2el;
  }
  return (double)((double)(ind1el + ind2el)) / 2.0;
}

int main()
{
  vector<int> a = {1, 4, 7, 10, 12};
  vector<int> b = {2, 3, 6, 15};
  cout << "The median of two sorted array is " << fixed << setprecision(1)
       << median(a, b) << '\n';
  return 0;
}
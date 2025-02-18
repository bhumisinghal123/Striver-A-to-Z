#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> arr)
{
  int xorr = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    xorr = xorr ^ arr[i];
  }
  return xorr;
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
  cout << getSingleElement(arr);
  return 0;
}
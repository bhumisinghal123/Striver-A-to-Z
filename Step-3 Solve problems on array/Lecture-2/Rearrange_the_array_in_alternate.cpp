// Equal no. of positive and negative integer
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(n, 0);
  int posIndex = 0, negIndex = 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] < 0)
    {
      ans[negIndex] = nums[i];
      negIndex += 2;
    }
    else
    {
      ans[posIndex] = nums[i];
      posIndex += 2;
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
  vector<int> result = rearrangeArray(arr);
  for (int i = 0; i < n; i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}
*/

// No. of positive and negative integer is not equal

#include <bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int> &a)
{
  vector<int> pos, neg;
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    if (a[i] > 0)
    {
      pos.push_back(a[i]);
    }
    else
    {
      neg.push_back(a[i]);
    }
  }

  if (pos.size() > neg.size())
  {
    for (int i = 0; i < neg.size(); i++)
    {
      a[2 * i] = pos[i];
      a[2 * i + 1] = neg[i];
    }
    int index = neg.size() * 2;
    for (int i = neg.size(); i < pos.size(); i++)
    {
      a[index] = pos[i];
      index++;
    }
  }

  else
  {
    for (int i = 0; i < pos.size(); i++)
    {
      a[2 * i] = neg[i];
      a[2 * i + 1] = pos[i];
    }
    int index = pos.size() * 2;
    for (int i = pos.size(); i < neg.size(); i++)
    {
      a[index] = neg[i];
      index++;
    }
  }
  return a;
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
  vector<int> result = alternateNumbers(arr);
  for (int i = 0; i < n; i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}
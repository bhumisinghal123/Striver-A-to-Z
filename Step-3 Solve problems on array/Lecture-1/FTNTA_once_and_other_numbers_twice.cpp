/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getSingleElement(vector<int> &arr)
  {
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      int num = arr[i];
      int cnt = 0;

      for (int j = 0; j < n; j++)
      {
        if (arr[j] == num)
          cnt++;
      }

      if (cnt == 1)
        return num;
    }

    return -1;
  }
};

int main()
{
  vector<int> arr = {4, 1, 2, 1, 2};

  Solution obj;
  int ans = obj.getSingleElement(arr);

  cout << "The single element is: " << ans << endl;

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getSingleElement(vector<int> &arr)
  {
    int n = arr.size();

    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
      maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);

    for (int i = 0; i < n; i++)
    {
      hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
      if (hash[arr[i]] == 1)
        return arr[i];
    }

    return -1;
  }
};

int main()
{
  vector<int> arr = {4, 1, 2, 1, 2};

  Solution obj;
  int ans = obj.getSingleElement(arr);

  cout << "The single element is: " << ans << endl;

  return 0;
}
*/

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
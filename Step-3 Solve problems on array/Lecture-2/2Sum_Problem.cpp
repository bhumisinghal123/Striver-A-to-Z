/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSumIndices(vector<int> &arr, int target)
  {
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (arr[i] + arr[j] == target)
        {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }
};

int main()
{
  Solution sol;

  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  vector<int> res = sol.twoSumIndices(arr, target);
  cout << "[" << res[0] << ", " << res[1] << "]\n";

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSumIndices(vector<int> &arr, int target)
  {
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int complement = target - arr[i];
      if (mp.find(complement) != mp.end())
      {
        return {mp[complement], i};
      }
      mp[arr[i]] = i;
    }
    return {-1, -1};
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;

  vector<int> res = sol.twoSumIndices(arr, target);
  cout << "[" << res[0] << ", " << res[1] << "]\n";

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
  int left = 0, right = n - 1;
  sort(book.begin(), book.end());
  while (left < right)
  {
    int sum = book[left] + book[right];
    if (sum == target)
    {
      return "YES";
    }
    else if (sum < target)
      left++;
    else
      right--;
  }
  return "NO";
}

int main()
{
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << read(n, arr, k);
  return 0;
}
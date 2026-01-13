/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &a, int N)
  {
    for (int i = 1; i <= N; i++)
    {
      int flag = 0;

      for (int j = 0; j < N - 1; j++)
      {
        if (a[j] == i)
        {
          flag = 1;
          break;
        }
      }

      if (flag == 0)
        return i;
    }

    return -1;
  }
};

int main()
{
  int N = 5;
  vector<int> a = {1, 2, 4, 5};

  Solution obj;
  int ans = obj.missingNumber(a, N);
  cout << "The missing number is: " << ans << endl;

  return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &a, int N)
  {
    int sum = (N * (N + 1)) / 2;

    int s2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
      s2 += a[i];
    }

    return sum - s2;
  }
};

int main()
{
  int N = 5;
  vector<int> a = {1, 2, 4, 5};

  Solution obj;
  int ans = obj.missingNumber(a, N);
  cout << "The missing number is: " << ans << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{
  int xor1 = 0, xor2 = 0;
  int n = N - 1;
  for (int i = 0; i < n; i++)
  {
    xor2 = xor2 ^ a[i];
    xor1 = xor1 ^ (i + 1);
  }
  xor1 = xor1 ^ N;
  return xor1 ^ xor2;
}

int main()
{
  int N;
  cin >> N;
  vector<int> a(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a[i];
  }
  cout << missingNumber(a, N) << endl;
  return 0;
}
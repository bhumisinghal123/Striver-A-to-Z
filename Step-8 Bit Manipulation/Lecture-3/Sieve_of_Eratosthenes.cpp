/*
#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
  int cnt = 0;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      cnt++;
      if ((n / i) != i)
      {
        cnt++;
      }
    }
  }
  if (cnt == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int primeNo(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (prime(i))
      cout<<i<<" ";
  }
}

int main()
{
  int n;
  cin >> n;
  primeNo(n);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int primeNo(int n)
{
  vector<int> prime(n + 1, 1);
  for (int i = 2; i <= n; i++)
  {
    prime[i] = 1;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= n; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1)
      cout << i << " ";
  }
}

int main()
{
  int n;
  cin >> n;
  primeNo(n);
  return 0;
}
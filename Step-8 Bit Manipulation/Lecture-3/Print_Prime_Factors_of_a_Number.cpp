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

int primeFactors(int n)
{
  vector<int> ls;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      if (prime(i))
        ls.push_back(i);
    }
    if (n / i != i)
    {
      if (prime(n / i))
        ls.push_back(n / i);
    }
  }
  sort(ls.begin(), ls.end());
  for (auto it : ls)
    cout << it << " ";
}

int main()
{
  int n;
  cin >> n;
  primeFactors(n);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int primeFactors(int n)
{
  vector<int> ls;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      ls.push_back(i);
      while (n % i == 0)
      {
        n = n / i;
      }
    }
  }
  if (n != 1)
    ls.push_back(n);
  sort(ls.begin(), ls.end());
  for (auto it : ls)
    cout << it << " ";
}

int main()
{
  int n;
  cin >> n;
  primeFactors(n);
  return 0;
}
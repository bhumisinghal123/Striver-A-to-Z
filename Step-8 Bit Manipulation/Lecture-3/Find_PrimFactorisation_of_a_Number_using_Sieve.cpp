/*
#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n)
{
  vector<int> ls;
  for (int i = 2; i <= sqrt(n); i++)
  {
    while (n % i == 0)
    {
      ls.push_back(i);
      n /= i;
    }
  }
  if (n != 1)
    ls.push_back(n);

  sort(ls.begin(), ls.end());
  return ls;
}

void primeFactorizationSieve(vector<int> queries)
{
  for (int i = 0; i < queries.size(); i++)
  {
    vector<int> ls = primeFactors(queries[i]);
    for (int x : ls)
      cout << x << " ";
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> queries = {n};
  primeFactorizationSieve(queries);
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void primeFactorizationSieve(vector<int> queries)
{
  const int MAX = 1e5 + 1;
  vector<int> spf(MAX);
  for (int i = 0; i < MAX; i++)
  {
    spf[i] = i;
  }
  for (int i = 2; i * i < MAX; i++)
  {
    if (spf[i] == i)
    {
      for (int j = i * i; j < MAX; j += i)
      {
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }
  for (int i = 0; i < queries.size(); i++)
  {
    int n = queries[i];
    while (n != 1)
    {
      cout << spf[n] << " ";
      n = n / spf[n];
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> queries = {n};
  primeFactorizationSieve(queries);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Pairs
void explainPair()
{
  pair<int, int> p = {1, 3};
  cout << p.first << " " << p.second;
  pair<int, pair<int, int>> p = {1, {3, 4}};
  cout << p.first << " " << p.second.second << " " << p.second.first;
  pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
  cout << arr[1].second;
}

// Vectors
void explainVector()
{

  vector<int> v;
  v.push_back(1);
  v.emplace_back(2);

  vector<pair<int, int>> vec;

  v.push_back({1, 2});
  v.emplace_back(1, 2);

  vector<int> v(5, 100);

  vector<int> v(5);

  vector<int> v1(5, 20);
  vector<int> v2(v1);

  vector<int>::iterator it = v.begin();

  it++;
  cout << *(it) << " ";

  it = it + 2;
  cout << *(it) << " ";

  vector<int>::iterator it = v.end();
  vector<int>::iterator it = v.rend();
  vector<int>::iterator it = v.rbegin();

  cout << v[0] << " " << v.at(0);
  cout << v.back() << " ";

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << *(it) << " ";
  }

  for (auto it = v.begin(); it != v.end(); it++)
  {
    cout << *(it) << " ";
  }
}

int main()
{
  return 0;
}
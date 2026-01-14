/*
#include <bits/stdc++.h>
using namespace std;

int sortArr(vector<int> &arr)
{
  sort(arr.begin(), arr.end());

  return arr[arr.size() - 1];
}

int main()
{
  vector<int> arr1 = {2, 5, 1, 3, 0};

  cout << "The Largest element in the array is: " << sortArr(arr1) << endl;

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr)
{
  int largest = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] > largest)
      largest = arr[i];
  }
  return largest;
}

int main()
{
  vector<int> arr1 = {2, 5, 1, 3, 0};

  cout << "The Largest element in the array is: " << largestElement(arr1) << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class InversionCounter
{
private:
  long long cnt;

  void merge(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        cnt += (mid - left + 1);
        right++;
      }
    }

    while (left <= mid)
    {
      temp.push_back(arr[left]);
      left++;
    }

    while (right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }
  }

  void mergeSort(vector<int> &arr, int low, int high)
  {
    if (low >= high)
      return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }

public:
  InversionCounter()
  {
    cnt = 0;
  }

  long long countInversions(vector<int> &arr)
  {
    cnt = 0;
    mergeSort(arr, 0, arr.size() - 1);
    return cnt;
  }
};

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  InversionCounter ic;
  long long inversions = ic.countInversions(arr);
  cout << "Number of inversions: " << inversions << endl;

  return 0;
}

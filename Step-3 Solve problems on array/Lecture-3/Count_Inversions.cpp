#include <iostream>
#include <vector>
using namespace std;

class InversionCounter
{
private:
  vector<int> arr;

  int merge(int low, int mid, int high)
  {
    vector<int> temp;
    int left = low, right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high)
    {
      if (arr[left] <= arr[right])
      {
        temp.push_back(arr[left++]);
      }
      else
      {
        temp.push_back(arr[right++]);
        cnt += (mid - left + 1); // count inversions
      }
    }

    while (left <= mid)
      temp.push_back(arr[left++]);
    while (right <= high)
      temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
    {
      arr[i] = temp[i - low];
    }

    return cnt;
  }

  int mergeSort(int low, int high)
  {
    if (low >= high)
      return 0;
    int mid = (low + high) / 2;
    int cnt = 0;
    cnt += mergeSort(low, mid);
    cnt += mergeSort(mid + 1, high);
    cnt += merge(low, mid, high);
    return cnt;
  }

public:
  InversionCounter(const vector<int> &input)
  {
    arr = input;
  }

  long long countInversions()
  {
    return mergeSort(0, arr.size() - 1);
  }
};

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  InversionCounter counter(arr);
  cout << "Number of Inversions: " << counter.countInversions() << endl;

  return 0;
}

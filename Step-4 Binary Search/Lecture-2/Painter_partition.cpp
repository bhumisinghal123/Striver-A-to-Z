/*
#include <bits/stdc++.h>
using namespace std;

class PainterPartition
{
public:
  int countPainters(vector<int> &boards, int time)
  {
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;

    for (int i = 0; i < n; i++)
    {
      if (boardsPainter + boards[i] <= time)
      {
        boardsPainter += boards[i];
      }
      else
      {
        painters++;
        boardsPainter = boards[i];
      }
    }
    return painters;
  }

  int findLargestMinDistance(vector<int> &boards, int k)
  {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++)
    {
      if (countPainters(boards, time) <= k)
      {
        return time;
      }
    }
    return low;
  }
};

int main()
{
  vector<int> boards = {10, 20, 30, 40};
  int k = 2;

  PainterPartition obj;
  int ans = obj.findLargestMinDistance(boards, k);
  cout << "The answer is: " << ans << "\n";

  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
  int students = 1;
  long long pagesStudent = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (pagesStudent + arr[i] <= pages)
    {
      pagesStudent += arr[i];
    }
    else
    {
      students += 1;
      pagesStudent = arr[i];
    }
  }
  return students;
}

int findPages(vector<int> &arr, int n, int m)
{
  if (m > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int students = countStudents(arr, mid);
    if (students > m)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return low;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
  return findPages(boards, boards.size(), k);
}

int main()
{
  vector<int> arr = {25, 46, 28, 49, 24};
  int m = 2;
  int ans = findLargestMinDistance(arr, m);
  cout << "The answer is: " << ans << "\n";
  return 0;
}
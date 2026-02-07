/*
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
  int low = 1, high = n;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    long long val = (mid * mid);
    if (val <= n)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return high;
}

int main()
{
  int n = 28;
  int ans = floorSqrt(n);
  cout << "The floor of square root of " << n << " is: " << ans << endl;
  return 0;
}
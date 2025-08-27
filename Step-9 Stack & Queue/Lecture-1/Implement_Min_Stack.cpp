#include <bits/stdc++.h>
using namespace std;

class MinStack
{
  stack<pair<int, int>> st;

public:
  void push(int x)
  {
    int minVal;
    if (st.empty())
    {
      minVal = x;
    }
    else
    {
      minVal = std::min(st.top().second, x);
    }
    st.push({x, minVal});
  }

  void pop()
  {
    if (!st.empty())
      st.pop();
    else
      cout << "Stack is empty, cannot pop.\n";
  }

  int top()
  {
    if (!st.empty())
      return st.top().first;
    else
    {
      cout << "Stack is empty.\n";
      return -1;
    }
  }

  int getMin()
  {
    if (!st.empty())
      return st.top().second;
    else
    {
      cout << "Stack is empty.\n";
      return -1;
    }
  }

  bool empty()
  {
    return st.empty();
  }
};

int main()
{
  MinStack ms;

  ms.push(5);
  ms.push(3);
  ms.push(7);
  ms.push(2);

  cout << "Top element: " << ms.top() << endl;
  cout << "Minimum: " << ms.getMin() << endl;

  ms.pop();
  cout << "Top element after pop: " << ms.top() << endl;
  cout << "Minimum after pop: " << ms.getMin() << endl;

  ms.pop();
  cout << "Minimum after another pop: " << ms.getMin() << endl;

  return 0;
}

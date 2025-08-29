#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
  return (!isalpha(c) && !isdigit(c));
}

string prefixToPostfix(string exp)
{
  stack<string> st;
  int n = exp.length();
  for (int i = n - 1; i >= 0; i--)
  {
    char c = exp[i];
    if (!isOperator(c))
    {
      string op(1, c);
      st.push(op);
    }
    else
    {
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string con = t1 + t2 + c;
      st.push(con);
    }
  }
  return st.top();
}

int main()
{
  string prefix = "*+AB-CD";
  cout << "Prefix: " << prefix << endl;
  cout << "Postfix: " << prefixToPostfix(prefix) << endl;
  return 0;
}

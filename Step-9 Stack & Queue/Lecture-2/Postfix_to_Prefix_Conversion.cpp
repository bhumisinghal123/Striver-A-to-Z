#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
  return (!isalpha(c) && !isdigit(c));
}

string postfixToPrefix(string exp)
{
  stack<string> st;
  int n = exp.length();

  for (int i = 0; i < n; i++)
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
      string con = c + t2 + t1;
      st.push(con);
    }
  }
  return st.top();
}

int main()
{
  string postfix = "AB+C*";
  cout << "Postfix: " << postfix << endl;
  cout << "Prefix: " << postfixToPrefix(postfix) << endl;
  return 0;
}

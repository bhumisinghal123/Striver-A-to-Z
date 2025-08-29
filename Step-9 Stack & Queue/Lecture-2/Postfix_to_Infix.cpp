#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
  return (!isalpha(c) && !isdigit(c));
}

string postfixToInfix(string exp)
{
  stack<string> st;

  for (int i = 0; i < exp.length(); i++)
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
      string con = "(" + t2 + c + t1 + ")";
      st.push(con);
    }
  }
  return st.top();
}

int main()
{
  string postfix = "ab+c*";
  cout << "Infix: " << postfixToInfix(postfix) << endl;
  return 0;
}

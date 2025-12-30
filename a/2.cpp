#include <bits/stdc++.h>
using namespace std;

bool checkString(unordered_set<string> &st, string complexWords)
{

  int i = 0;
  int n = complexWords.size();
  string temp;

  while (i < n)
  {
    if (isupper(complexWords[i]))
    {
      if (st.find(temp) != st.end())
      {
        temp.clear();
        temp.push_back(tolower(complexWords[i]));
      }
      else
      {
        return false;
      }
    }
    else
    {
      temp.push_back(complexWords[i]);
    }
    i++;
  }

  if (st.find(temp) != st.end())
    return true;

  else
    return false;
}

int main()
{
  vector<string> words = {"mobile", "phone", "case"};
  string complexWords = "mobilePhoneCase";

  unordered_set<string> st;

  for (auto word : words)
  {
    st.insert(word);
  }

  bool ans = checkString(st, complexWords);
  cout << ans;

  return 0;
}
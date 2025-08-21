#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  string data;
  Node *next;
  Node *back;
  Node() : data(""), next(nullptr), back(nullptr) {}
  Node(string x) : data(x), next(nullptr), back(nullptr) {}
  Node(string x, Node *next, Node *random) : data(x), next(next), back(random) {}
};

class Browser
{
  Node *currentPage;

public:
  Browser(string homepage)
  {
    currentPage = new Node(homepage);
  }

  void visit(string url)
  {
    Node *newNode = new Node(url);
    currentPage->next = newNode;
    newNode->back = currentPage;
    currentPage = newNode;
  }

  string back(int steps)
  {
    while (steps && currentPage->back)
    {
      currentPage = currentPage->back;
      steps--;
    }
    return currentPage->data;
  }

  string forward(int steps)
  {
    while (steps && currentPage->next)
    {
      currentPage = currentPage->next;
      steps--;
    }
    return currentPage->data;
  }
};

int main()
{
  Browser browser("google.com");

  browser.visit("youtube.com");
  browser.visit("github.com");
  browser.visit("leetcode.com");

  cout << "Current Page: " << browser.back(1) << "\n";
  cout << "Current Page: " << browser.back(1) << "\n";
  cout << "Current Page: " << browser.forward(1) << "\n";
  cout << "Current Page: " << browser.forward(2) << "\n";

  return 0;
}

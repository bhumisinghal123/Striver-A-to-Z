#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *findTail(Node *head)
{
  Node *tail = head;
  while (tail->next != NULL)
    tail = tail->next;
  return tail;
}
vector<pair<int, int>> findPairs(Node *head, int k)
{
  vector<pair<int, int>> ans;
  if (head == NULL)
    return ans;
  Node *left = head;
  Node *right = findTail(head);
  while (left->data < right->data)
  {
    if (left->data + right->data == k)
    {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->back;
    }
    else if (left->data + right->data < k)
    {
      left = left->next;
    }
    else
      right = right->back;
  }
  return ans;
}

void insertEnd(Node *&head, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *tail = head;
  while (tail->next != NULL)
    tail = tail->next;
  tail->next = newNode;
  newNode->back = tail;
}

int main()
{
  Node *head = NULL;
  insertEnd(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 4);
  insertEnd(head, 5);
  insertEnd(head, 6);
  insertEnd(head, 8);
  insertEnd(head, 9);

  cout << "Doubly Linked List: ";
  print(head);

  int k = 7;
  vector<pair<int, int>> result = findPairs(head, k);

  cout << "Pairs with sum " << k << ": ";
  for (auto &p : result)
  {
    cout << "(" << p.first << ", " << p.second << ") ";
  }
  cout << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

// struct || class
struct Node
{
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

Node *convertArr2LL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

void print(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *SegregatetoOddEVen(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *evenHead = head;
  Node *oddHead = head->next;

  Node *even = evenHead;
  Node *odd = oddHead;

  while (odd && odd->next)
  {
    even->next = odd->next;
    even = even->next;
    odd->next = even->next;
    odd = odd->next;
  }

  even->next = oddHead;
  return evenHead;
}

int main()
{
  vector<int> arr = {12, 15, 18, 19};
  Node *head = convertArr2LL(arr);
  head = SegregatetoOddEVen(head);
  print(head);
  return 0;
}
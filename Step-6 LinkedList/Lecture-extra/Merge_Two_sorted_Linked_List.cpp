#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

void printList(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

Node *sortTwoLists(Node *list1, Node *list2)
{
  Node *t1 = list1;
  Node *t2 = list2;
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (t1 != NULL && t2 != NULL)
  {
    if (t1->data < t2->data)
    {
      temp->next = t1;
      temp = t1;
      t1 = t1->next;
    }
    else
    {
      temp->next = t2;
      temp = t2;
      t2 = t2->next;
    }
  }
  if (t1)
    temp->next = t1;
  else
    temp->next = t2;
  return dummyNode->next;
}

int main()
{
  Node *list1 = new Node(1, new Node(3, new Node(5)));
  Node *list2 = new Node(2, new Node(4, new Node(6)));

  cout << "List 1: ";
  printList(list1);
  cout << "List 2: ";
  printList(list2);

  Node *merged = sortTwoLists(list1, list2);

  cout << "Merged List: ";
  printList(merged);
  return 0;
}
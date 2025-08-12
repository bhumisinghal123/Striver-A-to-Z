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

Node *deleteAllOccurences(Node *head, int k)
{
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == k)
    {
      if (temp == head)
      {
        head = temp->next;
      }

      Node *nextNode = temp->next;
      Node *prevNode = temp->back;
      if (nextNode != NULL)
        nextNode->back = prevNode;
      if (prevNode != NULL)
        prevNode->next = nextNode;

      free(temp);
      temp = nextNode;
    }
    else
    {
      temp = temp->next;
    }
  }
  return head;
}

int main()
{
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
  Node *fourth = new Node(2);
  Node *fifth = new Node(4);

  head->next = second;
  second->back = head;
  second->next = third;
  third->back = second;
  third->next = fourth;
  fourth->back = third;
  fourth->next = fifth;
  fifth->back = fourth;

  cout << "Original list: ";
  print(head);

  int k = 2;
  head = deleteAllOccurences(head, k);

  cout << "List after deleting " << k << ": ";
  print(head);

  return 0;
}
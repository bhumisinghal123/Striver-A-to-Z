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

Node *removeDuplicates(Node *head)
{
  Node *temp = head;
  while (temp != NULL && temp->next != NULL)
  {
    Node *nextNode = temp->next;
    while (nextNode != NULL && nextNode->data == temp->data)
    {
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      free(duplicate);
    }
    temp->next = nextNode;
    if (nextNode != NULL)
      nextNode->back = temp;

    temp = temp->next;
  }
  return head;
}

int main()
{
  Node *head = NULL;
  insertEnd(head, 1);
  insertEnd(head, 1);
  insertEnd(head, 2);
  insertEnd(head, 2);
  insertEnd(head, 3);
  insertEnd(head, 3);
  insertEnd(head, 3);
  insertEnd(head, 4);

  cout << "Original list: ";
  print(head);

  head = removeDuplicates(head);

  cout << "After removing duplicates: ";
  print(head);
  return 0;
}
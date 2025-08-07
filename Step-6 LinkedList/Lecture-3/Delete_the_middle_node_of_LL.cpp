#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

/*
Node *deleteMiddle(Node *head)
{
  Node *temp = head;
  int n = 0;
  while (temp != NULL)
  {
    n++;
    temp = temp->next;
  }
  int res = n / 2;
  temp = head;
  while (temp != NULL)
  {
    res--;
    if (res == 0)
    {
      Node *middle = temp->next;
      temp->next = temp->next->next;
      free(middle);
      break;
    }
    temp = temp->next;
  }
  return head;
}
*/

Node *deleteMiddle(Node *head)
{
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *slow = head;
  Node *fast = head;
  fast = head->next->next;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = slow->next->next;
  return head;
}

void printLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  cout << "Orginal Linked List: ";
  printLL(head);
  head = deleteMiddle(head);
  cout << "Linked List after deletion: ";
  printLL(head);
  return 0;
}

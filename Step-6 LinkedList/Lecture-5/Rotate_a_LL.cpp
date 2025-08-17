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

Node *findNthNode(Node *temp, int k)
{
  int cnt = 1;
  while (temp != NULL)
  {
    if (cnt == k)
      return temp;
    cnt++;
    temp = temp->next;
  }
  return temp;
}

Node *rotate(Node *head, int k)
{
  if (head == NULL || k == 0)
    return head;
  Node *tail = head;
  int len = 1;
  while (tail->next != NULL)
  {
    tail = tail->next;
    len += 1;
  }

  if (k % len == 0)
    return head;

  k = k % len;

  tail->next = head;
  Node *newLastNode = findNthNode(head, len - k);

  head = newLastNode->next;
  newLastNode->next = NULL;
  return head;
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << "Original List: ";
  printList(head);

  int k = 4;
  head = rotate(head, k);

  cout << "Rotated List by " << k << ": ";
  printList(head);

  return 0;
}
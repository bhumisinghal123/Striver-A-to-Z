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

Node *reverseLinkedList(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *newHead = reverseLinkedList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;
}

Node *getKthNode(Node *temp, int k)
{
  k--;
  while (temp != NULL && k > 0)
  {
    temp = temp->next;
    k--;
  }
  return temp;
}

Node *kReverse(Node *head, int k)
{
  Node *temp = head;
  Node *prevLast = NULL;

  while (temp != NULL)
  {
    Node *kthNode = getKthNode(temp, k);
    if (kthNode == NULL)
    {
      if (prevLast)
        prevLast->next = temp;
      break;
    }

    Node *nextNode = kthNode->next;
    kthNode->next = NULL;

    Node *newHead = reverseLinkedList(temp);

    if (temp == head)
    {
      head = kthNode;
    }
    else
    {
      prevLast->next = kthNode;
    }

    prevLast = temp;
    temp = nextNode;
  }
  return head;
}

int main()
{
  Node *head = new Node(1);
  Node *temp = head;
  for (int i = 2; i <= 8; i++)
  {
    temp->next = new Node(i);
    temp = temp->next;
  }

  cout << "Original list: ";
  printList(head);

  int k = 3;
  head = kReverse(head, k);

  cout << "List after reversing in groups of " << k << ": ";
  printList(head);

  return 0;
}

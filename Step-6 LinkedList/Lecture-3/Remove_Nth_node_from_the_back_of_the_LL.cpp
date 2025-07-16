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

Node *removeKthNode(Node *head, int k)
{
  Node *fast = head;
  Node *slow = head;
  for (int i = 0; i < k; i++)
    fast = fast->next;
  if (fast == NULL)
    return head->next;
  while (fast->next != NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }
  Node *delNode = slow->next;
  slow->next = slow->next->next;
  free(delNode);
  return head;
}

int main()
{
  vector<int> arr = {12, 13, 4, 17, 15};
  Node *head = convertArr2LL(arr);
  head = removeKthNode(head, 2);
  print(head);
  return 0;
}
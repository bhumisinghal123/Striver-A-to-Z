
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

Node *reverseLLRecursive(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *newHead = reverseLLRecursive(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

int main()
{
  vector<int> arr = {12, 17, 16, 15};
  Node *head = convertArr2LL(arr);
  head = reverseLLRecursive(head);
  print(head);
  return 0;
}
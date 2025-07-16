/*
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

Node *sortLL(Node *head)
{
  Node *temp = head;
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  while (temp != NULL)
  {
    if (temp->data == 0)
    {
      cnt0++;
    }
    else if (temp->data == 1)
    {
      cnt1++;
    }
    else
    {
      cnt2++;
    }
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL)
  {
    if (cnt0)
    {
      temp->data = 0;
      cnt0--;
    }
    else if (cnt1)
    {
      temp->data = 1;
      cnt1--;
    }
    else
    {
      temp->data = 2;
      cnt2--;
    }
    temp = temp->next;
  }
  return head;
}

int main()
{
  vector<int> arr = {0, 1, 0, 1, 2, 0, 1, 2};
  Node *head = convertArr2LL(arr);
  head = sortLL(head);
  print(head);
  return 0;
}
*/

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

Node *sortLL(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);

  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;
  Node *temp = head;

  while (temp)
  {
    if (temp->data == 0)
    {
      zero->next = temp;
      zero = zero->next;
    }
    else if (temp->data == 1)
    {
      one->next = temp;
      one = one->next;
    }
    else
    {
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }

  zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
  one->next = twoHead->next;
  two->next = NULL;

  Node *newHead = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;
  return newHead;
}

int main()
{
  vector<int> arr = {0, 1, 0, 1, 2, 0, 1, 2};
  Node *head = convertArr2LL(arr);
  head = sortLL(head);
  print(head);
  return 0;
}
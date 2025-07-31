
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

/*
Node *findMiddle(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *temp = head;
  int count = 0;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  int mid = count / 2 + 1;
  temp = head;
  while (temp != NULL)
  {
    mid = mid - 1;
    if (mid == 0)
    {
      break;
    }
    temp = temp->next;
  }
  return temp;
}
*/

Node *findMiddle(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main()
{
  vector<int> arr = {12, 16, 11, 12};
  Node *head = convertArr2LL(arr);
  Node *middleNode = findMiddle(head);
  cout << "The middle node value is: " << middleNode->data << endl;
  return 0;
}
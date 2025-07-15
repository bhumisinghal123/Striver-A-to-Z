#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct Node
{
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
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

Node *addTwoNumbers(Node *num1, Node *num2)
{
  Node *dummyHead = new Node(-1);
  Node *curr = dummyHead;
  Node *temp1 = num1;
  Node *temp2 = num2;
  int carry = 0;
  while (temp1 != NULL || temp2 != NULL)
  {
    int sum = carry;
    if (temp1)
      sum += temp1->data;
    if (temp2)
      sum += temp2->data;
    Node *newNode = new Node(sum % 10);
    carry = sum / 10;

    curr->next = newNode;
    curr = curr->next;

    if (temp1)
      temp1 = temp1->next;
    if (temp2)
      temp2 = temp2->next;
  }
  if (carry)
  {
    Node *newNode = new Node(carry);
    curr->next = newNode;
  }
  return dummyHead->next;
}

int main()
{
  vector<int> num1 = {2, 4, 3};
  vector<int> num2 = {5, 6, 4};

  Node *head1 = convertArr2LL(num1);
  Node *head2 = convertArr2LL(num2);

  Node *result = addTwoNumbers(head1, head2);

  cout << "Result: ";
  print(result);

  return 0;
}
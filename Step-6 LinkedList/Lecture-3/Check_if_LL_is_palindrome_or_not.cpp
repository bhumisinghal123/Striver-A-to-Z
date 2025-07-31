
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
bool isPalindrome(Node *head)
{

  stack<int> st;
  Node *temp = head;
  while (temp != NULL)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL)
  {
    if (temp->data != st.top())
    {
      return false;
    }
    st.pop();
    temp = temp->next;
  }
  return true;
}
*/

Node *reverseLL(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

bool isPalindrome(Node *head)
{
  if (head == NULL || head->next == NULL)
    return true;
  Node *slow = head;
  Node *fast = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *newHead = reverseLL(slow->next);
  Node *first = head;
  Node *second = newHead;
  while (second != NULL)
  {
    if (first->data != second->data)
    {
      reverseLL(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  reverseLL(newHead);
  return true;
}

int main()
{
  vector<int> arr = {12, 11, 5, 11, 12};
  Node *head = convertArr2LL(arr);
  if (isPalindrome(head))
  {
    cout << "The linked list is a palindrome." << endl;
  }
  else
  {
    cout << "The linked list is not a palindrome." << endl;
  }
  return 0;
}

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

Node *reverseLLIterative(Node *head)
{
  Node *temp = head;
  stack<int> st;
  while (temp != nullptr)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr)
  {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

int main()
{
  vector<int> arr = {12, 17, 16, 15};
  Node *head = convertArr2LL(arr);
  head = reverseLLIterative(head);
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

Node *reverseLLIterative(Node *head)
{
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

int main()
{
  vector<int> arr = {12, 17, 16, 15};
  Node *head = convertArr2LL(arr);
  head = reverseLLIterative(head);
  print(head);
  return 0;
}
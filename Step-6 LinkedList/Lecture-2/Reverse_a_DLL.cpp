/*
#include <bits/stdc++.h>
using namespace std;

// struct || class
struct Node
{
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArr2DLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
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
}

Node *reverseDLL(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
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
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7, 4};
  Node *head = convertArr2DLL(arr);
  cout << endl
       << "Doubly Linked List Initially:  " << endl;
  print(head);
  cout << endl
       << "Doubly Linked List After Reversing " << endl;
  head = reverseDLL(head);
  print(head);
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
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }

public:
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArr2DLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
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
}

Node *reverseDLL(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *prev = NULL;
  Node *current = head;
  while (current != NULL)
  {
    prev = current->back;
    current->back = current->next;
    current->next = prev;
    current = current->back;
  }
  return prev->back;
}

int main()
{
  vector<int> arr = {12, 5, 8, 7, 4};
  Node *head = convertArr2DLL(arr);
  cout << endl
       << "Doubly Linked List Initially:  " << endl;
  print(head);
  cout << endl
       << "Doubly Linked List After Reversing " << endl;
  head = reverseDLL(head);
  print(head);
}
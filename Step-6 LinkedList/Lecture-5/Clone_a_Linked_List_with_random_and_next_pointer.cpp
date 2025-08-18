#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node *random;
  Node() : data(0), next(nullptr), random(nullptr) {};
  Node(int x) : data(x), next(nullptr), random(nullptr) {}
  Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};

/*
Node *cloneLL(Node *head)
{
  Node *temp = head;
  unordered_map<Node *, Node *> mpp;
  while (temp != NULL)
  {
    Node *newNode = new Node(temp->data);
    mpp[temp] = newNode;
    temp = temp->next;
  }

  temp = head;
  while (temp != NULL)
  {
    Node *copyNode = mpp[temp];
    copyNode->next = mpp[temp->next];
    copyNode->random = mpp[temp->random];
    temp = temp->next;
  }
  return mpp[head];
}
void printClonedLinkedList(Node *head)
{
  while (head != nullptr)
  {
    cout << "Data: " << head->data;
    if (head->random != nullptr)
    {
      cout << ", Random: " << head->random->data;
    }
    else
    {
      cout << ", Random: nullptr";
    }
    cout << endl;
    head = head->next;
  }
}

int main()
{
  Node *head = new Node(7);
  head->next = new Node(14);
  head->next->next = new Node(21);
  head->next->next->next = new Node(28);
  head->random = head->next->next;
  head->next->random = head;
  head->next->next->random = head->next->next->next;
  head->next->next->next->random = head->next;

  cout << "Original Linked List with Random Pointers:" << endl;
  printClonedLinkedList(head);

  Node *clonedList = cloneLL(head);
  cout << "\nCloned Linked List with Random Pointers:" << endl;
  printClonedLinkedList(clonedList);

  return 0;
}
*/

void insertCopyBetween(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    Node *nextElement = temp->next;
    Node *copy = new Node(temp->data);
    copy->next = nextElement;
    temp->next = copy;
    temp = nextElement;
  }
}

void connectRandomPointers(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    Node *copyNode = temp->next;

    if (temp->random)
    {
      copyNode->random = temp->random->next;
    }
    else
    {
      copyNode->random = nullptr;
    }

    temp = temp->next->next;
  }
}

Node *getDeepCopyList(Node *head)
{
  Node *temp = head;
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;

  while (temp != NULL)
  {
    res->next = temp->next;
    res = res->next;
    temp->next = temp->next->next;
    temp = temp->next;
  }
  return dummyNode->next;
}

Node *cloneLL(Node *head)
{
  insertCopyBetween(head);
  connectRandomPointers(head);
  return getDeepCopyList(head);
}

void printList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << "Node: " << temp->data;
    if (temp->random)
      cout << ", Random: " << temp->random->data;
    else
      cout << ", Random: NULL";
    cout << endl;
    temp = temp->next;
  }
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);

  head->random = head->next->next;
  head->next->random = head;
  head->next->next->random = head->next;

  cout << "Original List:" << endl;
  printList(head);

  Node *clonedHead = cloneLL(head);

  cout << "\nCloned List:" << endl;
  printList(clonedHead);

  return 0;
}
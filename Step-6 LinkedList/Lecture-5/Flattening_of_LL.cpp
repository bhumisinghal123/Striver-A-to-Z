#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *child;
  Node() : data(0), next(nullptr), child(nullptr) {};
  Node(int x) : data(x), next(nullptr), child(nullptr) {}
  Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

void printLinkedList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->child;
  }
  cout << endl;
}

/*
Node *convertArrToLinkedList(vector<int> &arr)
{
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  for (int i = 0; i < arr.size(); i++)
  {
    temp->child = new Node(arr[i]);
    temp = temp->child;
  }
  return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
  vector<int> arr;
  while (head != nullptr)
  {
    Node *t2 = head;
    while (t2 != nullptr)
    {
      arr.push_back(t2->data);
      t2 = t2->child;
    }
    head = head->next;
  }
  sort(arr.begin(), arr.end());
  return convertArrToLinkedList(arr);
}

void printOriginalLinkedList(Node *head, int depth)
{
  while (head != nullptr)
  {
    cout << head->data;
    if (head->child)
    {
      cout << " -> ";
      printOriginalLinkedList(head->child, depth + 1);
    }
    if (head->next)
    {
      cout << endl;
      for (int i = 0; i < depth; ++i)
      {
        cout << "| ";
      }
    }
    head = head->next;
  }
}

int main()
{
  Node *head = new Node(5);
  head->child = new Node(14);

  head->next = new Node(10);
  head->next->child = new Node(4);

  head->next->next = new Node(12);
  head->next->next->child = new Node(20);
  head->next->next->child->child = new Node(13);

  head->next->next->next = new Node(7);
  head->next->next->next->child = new Node(17);

  cout << "Original linked list:" << endl;
  printOriginalLinkedList(head, 0);
  Node *flattened = flattenLinkedList(head);
  cout << "\nFlattened linked list: ";
  printLinkedList(flattened);

  return 0;
}
*/

Node *merge(Node *list1, Node *list2)
{
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;
  while (list1 != NULL && list2 != NULL)
  {
    if (list1->data < list2->data)
    {
      res->child = list1;
      res = list1;
      list1 = list1->child;
    }
    else
    {
      res->child = list2;
      res = list2;
      list2 = list2->child;
    }
    res->next = nullptr;
  }
  if (list1)
    res->child = list1;
  else
    res->child = list2;
  if (dummyNode->child)
    dummyNode->child->next = nullptr;
  return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  Node *mergedHead = flattenLinkedList(head->next);
  head = merge(head, mergedHead);
  return head;
}

int main()
{
  Node *head = new Node(5);
  head->child = new Node(7);
  head->child->child = new Node(8);
  head->child->child->child = new Node(30);

  head->next = new Node(10);
  head->next->child = new Node(20);

  head->next->next = new Node(19);
  head->next->next->child = new Node(22);
  head->next->next->child->child = new Node(50);

  head->next->next->next = new Node(28);
  head->next->next->next->child = new Node(35);
  head->next->next->next->child->child = new Node(40);
  head->next->next->next->child->child->child = new Node(45);

  Node *flatHead = flattenLinkedList(head);

  cout << "Flattened list: ";
  printLinkedList(flatHead);
  return 0;
}
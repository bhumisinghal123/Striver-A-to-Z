#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data1, Node *next1 = nullptr)
  {
    data = data1;
    next = next1;
  }
};

void printList(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

Node *mergeKLists(vector<Node *> &listArray)
{
  priority_queue<pair<int, Node *>,
                 vector<pair<int, Node *>>, greater<pair<int, Node *>>>
      pq;
  for (int i = 0; i < listArray.size(); i++)
  {
    if (listArray[i])
    {
      pq.push({listArray[i]->data, listArray[i]});
    }
  }
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    if (it.second->next)
      pq.push({it.second->next->data, it.second->next});
    temp->next = it.second;
    temp = temp->next;
  }
  return dummyNode->next;
}

int main()
{
  Node *list1 = new Node(1, new Node(4, new Node(7)));
  Node *list2 = new Node(2, new Node(5, new Node(8)));
  Node *list3 = new Node(3, new Node(6, new Node(9)));

  vector<Node *> listArray = {list1, list2, list3};

  Node *mergedHead = mergeKLists(listArray);

  cout << "Merged Linked List: ";
  printList(mergedHead);

  return 0;
}

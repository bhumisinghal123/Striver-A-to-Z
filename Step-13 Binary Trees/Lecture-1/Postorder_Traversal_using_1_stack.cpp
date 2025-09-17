#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> postOrderTraversal(Node *root)
{
  vector<int> postorder;
  if (root == NULL)
    return postorder;

  stack<Node *> st;
  Node *cur = root;
  Node *temp = nullptr;

  while (cur != NULL || !st.empty())
  {
    if (cur != NULL)
    {
      st.push(cur);
      cur = cur->left;
    }
    else
    {
      Node *node = st.top();
      if (node->right != NULL && temp != node->right)
      {
        cur = node->right;
      }
      else
      {
        postorder.push_back(node->data);
        temp = node;
        st.pop();
      }
    }
  }

  return postorder;
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> result = postOrderTraversal(root);

  cout << "Postorder Traversal: ";
  for (int val : result)
    cout << val << " ";
  return 0;
}

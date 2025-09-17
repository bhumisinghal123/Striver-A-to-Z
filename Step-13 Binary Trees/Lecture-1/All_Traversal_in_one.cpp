#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

tuple<vector<int>, vector<int>, vector<int>> preInPostTraversal(Node *root)
{
  vector<int> pre, in, post;
  if (root == NULL)
    return {pre, in, post};

  stack<pair<Node *, int>> st;
  st.push({root, 1});

  while (!st.empty())
  {
    auto it = st.top();
    st.pop();

    if (it.second == 1)
    {
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->left != NULL)
      {
        st.push({it.first->left, 1});
      }
    }
    else if (it.second == 2)
    {
      in.push_back(it.first->data);
      it.second++;
      st.push(it);

      if (it.first->right != NULL)
      {
        st.push({it.first->right, 1});
      }
    }
    else
    {
      post.push_back(it.first->data);
    }
  }

  return {pre, in, post};
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

  auto traversals = preInPostTraversal(root);
  vector<int> pre = get<0>(traversals);
  vector<int> in = get<1>(traversals);
  vector<int> post = get<2>(traversals);

  cout << "Preorder Traversal: ";
  for (int val : pre)
    cout << val << " ";
  cout << "\n";

  cout << "Inorder Traversal: ";
  for (int val : in)
    cout << val << " ";
  cout << "\n";

  cout << "Postorder Traversal: ";
  for (int val : post)
    cout << val << " ";
  cout << "\n";

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
private:
  stack<TreeNode *> myStack;

public:
  BSTIterator(TreeNode *root)
  {
    pushAll(root);
  }

  bool hasNext()
  {
    return !myStack.empty();
  }

  int next()
  {
    TreeNode *tmpNode = myStack.top();
    myStack.pop();
    pushAll(tmpNode->right);
    return tmpNode->val;
  }

private:
  void pushAll(TreeNode *node)
  {
    for (; node != NULL; myStack.push(node), node = node->left)
      ;
  }
};

int main()
{

  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator it(root);

  while (it.hasNext())
  {
    cout << it.next() << " ";
  }

  return 0;
}
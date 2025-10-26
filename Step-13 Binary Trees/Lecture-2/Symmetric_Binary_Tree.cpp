#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x)
  {
    val = x;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
    return root == NULL || isSymmetricHelp(root->left, root->right);
  }

  bool isSymmetricHelp(TreeNode *left, TreeNode *right)
  {
    if (left == NULL || right == NULL)
      return left == right;

    if (left->val != right->val)
      return false;

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
  }
};

void printInorder(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);

  Solution solution;

  cout << "Binary Tree (Inorder): ";
  printInorder(root);
  cout << endl;

  bool res;
  res = solution.isSymmetric(root);

  if (res)
  {
    cout << "This Tree is Symmetrical" << endl;
  }
  else
  {
    cout << "This Tree is NOT Symmetrical" << endl;
  }
  return 0;
}
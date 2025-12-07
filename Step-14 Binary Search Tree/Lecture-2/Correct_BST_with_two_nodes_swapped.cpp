#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
  TreeNode *first;
  TreeNode *prev;
  TreeNode *middle;
  TreeNode *last;

private:
  void inorder(TreeNode *root)
  {
    if (root == NULL)
      return;

    inorder(root->left);

    if (prev != NULL && (root->val < prev->val))
    {
      if (first == NULL)
      {
        first = prev;
        middle = root;
      }
      else
      {
        last = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root)
  {
    first = middle = last = prev = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if (first && last)
      swap(first->val, last->val);
    else if (first && middle)
      swap(first->val, middle->val);
  }
};

void printInorder(TreeNode *root)
{
  if (!root)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(2);

  cout << "Before Recovery (Inorder): ";
  printInorder(root);
  cout << endl;

  Solution sol;
  sol.recoverTree(root);

  cout << "After Recovery (Inorder): ";
  printInorder(root);
  cout << endl;
  return 0;
}
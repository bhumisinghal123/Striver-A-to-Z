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
public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
    {
      return NULL;
    }
    if (root->val == key)
    {
      return helper(root);
    }
    TreeNode *dummy = root;
    while (root != NULL)
    {
      if (root->val > key)
      {
        if (root->left != NULL && root->left->val == key)
        {
          root->left = helper(root->left);
          break;
        }
        else
        {
          root = root->left;
        }
      }
      else
      {
        if (root->right != NULL && root->right->val == key)
        {
          root->right = helper(root->right);
          break;
        }
        else
        {
          root = root->right;
        }
      }
    }
    return dummy;
  }

  TreeNode *helper(TreeNode *root)
  {
    if (root->left == NULL)
    {
      return root->right;
    }
    if (root->right == NULL)
    {
      return root->left;
    }
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
  }

  TreeNode *findLastRight(TreeNode *root)
  {
    if (root->right == NULL)
    {
      return root;
    }
    return findLastRight(root->right);
  }
};

void printInOrder(TreeNode *root)
{
  if (root == nullptr)
    return;
  printInOrder(root->left);
  cout << root->val << " ";
  printInOrder(root->right);
}

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  cout << "Binary Search Tree (Inorder): ";
  printInOrder(root);
  cout << endl;

  Solution solution;

  int key = 3;
  cout << "Deleting node with key = " << key << endl;

  root = solution.deleteNode(root, key);

  cout << "BST After Deletion (Inorder): ";
  printInOrder(root);
  cout << endl;

  return 0;
}
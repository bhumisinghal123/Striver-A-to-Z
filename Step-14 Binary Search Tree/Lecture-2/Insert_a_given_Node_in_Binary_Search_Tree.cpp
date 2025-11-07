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
  TreeNode *insertInBST(TreeNode *root, int val)
  {
    if (root == NULL)
      return new TreeNode(val);
    TreeNode *cur = root;
    while (true)
    {
      if (cur->val <= val)
      {
        if (cur->right != NULL)
          cur = cur->right;
        else
        {
          cur->right = new TreeNode(val);
          break;
        }
      }
      else
      {
        if (cur->left != NULL)
          cur = cur->left;
        else
        {
          cur->left = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};

void inorder(TreeNode *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

TreeNode *buildBST(vector<int> arr)
{
  Solution s;
  TreeNode *root = NULL;
  for (int val : arr)
  {
    root = s.insertInBST(root, val);
  }
  return root;
}

int main()
{
  Solution s;
  vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  TreeNode *root = buildBST(values);

  cout << "Inorder traversal before insertion: ";
  inorder(root);
  cout << endl;

  int valToInsert = 5;
  cout << "Inserting " << valToInsert << " into BST..." << endl;
  root = s.insertInBST(root, valToInsert);

  cout << "Inorder traversal after insertion: ";
  inorder(root);
  cout << endl;

  return 0;
}
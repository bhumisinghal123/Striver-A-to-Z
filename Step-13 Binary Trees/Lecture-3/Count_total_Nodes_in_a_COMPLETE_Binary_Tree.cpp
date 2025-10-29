/*
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
  void inorder(TreeNode *root, int &count)
  {
    if (root == NULL)
    {
      return;
    }
    count++;
    inorder(root->left, count);
    inorder(root->right, count);
  }

  int countNodes(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    int count = 0;
    inorder(root, count);
    return count;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  Solution sol;
  int totalNodes = sol.countNodes(root);
  cout << "Total number of nodes in the Complete Binary Tree: "
       << totalNodes << endl;

  return 0;
}
*/

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
  int countNodes(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh)
      return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  int findHeightLeft(TreeNode *node)
  {
    int hght = 0;
    while (node)
    {
      hght++;
      node = node->left;
    }
    return hght;
  }

  int findHeightRight(TreeNode *node)
  {
    int hght = 0;
    while (node)
    {
      hght++;
      node = node->right;
    }
    return hght;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  Solution sol;
  int totalNodes = sol.countNodes(root);
  cout << "Total number of nodes in the Complete Binary Tree: "
       << totalNodes << endl;

  return 0;
}
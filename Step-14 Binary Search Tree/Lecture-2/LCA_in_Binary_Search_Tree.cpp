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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == NULL)
      return NULL;
    int cur = root->val;
    if (cur < p->val && cur < q->val)
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (cur > p->val && cur > q->val)
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};

int main()
{
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  TreeNode *p = root->left;
  TreeNode *q = root->right;

  Solution s;
  TreeNode *ans = s.lowestCommonAncestor(root, p, q);

  if (ans)
    cout << "LCA = " << ans->val << endl;
  else
    cout << "LCA not found" << endl;
  return 0;
}
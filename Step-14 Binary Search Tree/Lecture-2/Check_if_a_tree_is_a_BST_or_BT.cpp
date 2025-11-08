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
  bool isValidBST(TreeNode *root)
  {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }

private:
  bool isValidBST(TreeNode *root, long minVal, long maxVal)
  {
    if (root == nullptr)
      return true;

    if (root->val <= minVal || root->val >= maxVal)
      return false;

    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
  }
};

int main()
{
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  Solution s;
  if (s.isValidBST(root))
    cout << "Valid BST\n";
  else
    cout << "Invalid BST\n";

  return 0;
}

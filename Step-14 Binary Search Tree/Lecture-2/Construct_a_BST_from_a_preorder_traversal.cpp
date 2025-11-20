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
  TreeNode *bstFromPreorder(vector<int> &A)
  {
    int i = 0;
    return build(A, i, INT_MAX);
  }

  TreeNode *build(vector<int> &A, int &i, int bound)
  {
    if (A.size() == i || A[i] > bound)
      return NULL;
    TreeNode *root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    return root;
  }
};

int main()
{
  vector<int> preorder = {8, 5, 1, 7, 10, 12};
  Solution s;
  TreeNode *root = s.bstFromPreorder(preorder);

  function<void(TreeNode *)> inorder = [&](TreeNode *node)
  {
    if (!node)
      return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
  };

  cout << "Inorder Traversal of the constructed BST: ";
  inorder(root);
  cout << endl;

  return 0;
}
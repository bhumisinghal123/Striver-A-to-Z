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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    if (inorder.size() != postorder.size())
      return NULL;

    map<int, int> hm;

    for (int i = 0; i < inorder.size(); ++i)
      hm[inorder[i]] = i;

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
  }

  TreeNode *buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &hm)
  {
    if (ps > pe || is > ie)
      return NULL;

    TreeNode *root = new TreeNode(postorder[pe]);

    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;

    root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);
    root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

    return root;
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

void printVector(vector<int> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> inorder = {40, 20, 50, 10, 60, 30};
  vector<int> postorder = {40, 50, 20, 60, 30, 10};

  cout << "Inorder Vector: ";
  printVector(inorder);

  cout << "Postorder Vector: ";
  printVector(postorder);

  Solution sol;

  TreeNode *root = sol.buildTree(inorder, postorder);

  cout << "Inorder of Unique Binary Tree Created: " << endl;
  printInorder(root);
  cout << endl;

  return 0;
}

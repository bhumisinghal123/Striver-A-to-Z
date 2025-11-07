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
  TreeNode *prev = NULL;
  void flatten(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};

void printPreorder(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printFlattenTree(root->right);
}

int main()
{

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->left = new TreeNode(8);

  Solution sol;

  cout << "Binary Tree Preorder: ";
  printPreorder(root);
  cout << endl;

  sol.flatten(root);

  cout << "Binary Tree After Flatten: ";
  printFlattenTree(root);
  cout << endl;

  return 0;
}
*/

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
  TreeNode *prev = NULL;
  void flatten(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
      TreeNode *cur = st.top();
      st.pop();
      if (cur->right != NULL)
      {
        st.push(cur->right);
      }
      if (cur->left != NULL)
      {
        st.push(cur->left);
      }
      if (!st.empty())
      {
        cur->right = st.top();
      }
      cur->left = NULL;
    }
  }
};

void printPreorder(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printFlattenTree(root->right);
}

int main()
{

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->left = new TreeNode(8);

  Solution sol;

  cout << "Binary Tree Preorder: ";
  printPreorder(root);
  cout << endl;

  sol.flatten(root);

  cout << "Binary Tree After Flatten: ";
  printFlattenTree(root);
  cout << endl;

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
  void flatten(TreeNode *root)
  {
    TreeNode *cur = root;
    while (cur)
    {
      if (cur->left)
      {
        TreeNode *pre = cur->left;
        while (pre->right)
        {
          pre = pre->right;
        }
        pre->right = cur->right;
        cur->right = cur->left;
        cur->left = NULL;
      }
      cur = cur->right;
    }
  }
};

void printPreorder(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printFlattenTree(TreeNode *root)
{
  if (!root)
  {
    return;
  }
  cout << root->val << " ";
  printFlattenTree(root->right);
}

int main()
{

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->right->left = new TreeNode(8);

  Solution sol;

  cout << "Binary Tree Preorder: ";
  printPreorder(root);
  cout << endl;

  sol.flatten(root);

  cout << "Binary Tree After Flatten: ";
  printFlattenTree(root);
  cout << endl;

  return 0;
}

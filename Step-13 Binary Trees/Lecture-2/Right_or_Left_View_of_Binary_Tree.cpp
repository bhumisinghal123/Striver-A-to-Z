/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  vector<int> rightsideView(Node *root)
  {
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    for (auto level : levelTraversal)
    {
      res.push_back(level.back());
    }
    return res;
  }

  vector<int> leftsideView(Node *root)
  {
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    for (auto level : levelTraversal)
    {
      res.push_back(level.front());
    }
    return res;
  }

private:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<vector<int>> ans;
    if (!root)
    {
      return ans;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size; i++)
      {
        Node *top = q.front();
        level.push_back(top->data);
        q.pop();
        if (top->left != NULL)
        {
          q.push(top->left);
        }
        if (top->right != NULL)
        {
          q.push(top->right);
        }
      }
      ans.push_back(level);
    }
    return ans;
  }
};

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(10);
  root->left->left->right = new Node(5);
  root->left->left->right->right = new Node(6);
  root->right = new Node(3);
  root->right->right = new Node(10);
  root->right->left = new Node(9);

  Solution solution;

  vector<int> rightView = solution.rightsideView(root);
  cout << "Right View Traversal: ";
  for (auto node : rightView)
  {
    cout << node << " ";
  }
  cout << endl;

  vector<int> leftView = solution.leftsideView(root);
  cout << "Left View Traversal: ";
  for (auto node : leftView)
  {
    cout << node << " ";
  }
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
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    recursion(root, 0, res);
    return res;
  }

  void recursion(TreeNode *root, int level, vector<int> &res)
  {
    if (root == NULL)
      return;
    if (res.size() == level)
      res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(10);
  root->left->left->right = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(10);
  root->right->left = new TreeNode(9);

  Solution solution;

  vector<int> rightView = solution.rightSideView(root);

  cout << "Right View Traversal: ";
  for (auto node : rightView)
  {
    cout << node << " ";
  }
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
  vector<int> leftSideView(TreeNode *root)
  {
    vector<int> res;

    recursion(root, 0, res);

    return res;
  }

  void recursion(TreeNode *root, int level, vector<int> &res)
  {
    if (root == NULL)
    {
      return;
    }
    if (res.size() == level)
    {
      res.push_back(root->val);
    }
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(10);
  root->left->left->right = new TreeNode(5);
  root->left->left->right->right = new TreeNode(6);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(10);
  root->right->left = new TreeNode(9);

  Solution solution;

  vector<int> rightView = solution.leftSideView(root);

  cout << "Left View Traversal: ";
  for (auto node : rightView)
  {
    cout << node << " ";
  }
  cout << endl;
  return 0;
}

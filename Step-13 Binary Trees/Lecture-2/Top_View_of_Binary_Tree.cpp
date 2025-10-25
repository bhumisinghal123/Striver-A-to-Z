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
  vector<int> topView(TreeNode *root)
  {
    vector<int> ans;
    if (root == NULL)
      return ans;

    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      TreeNode *node = it.first;
      int line = it.second;

      if (mpp.find(line) == mpp.end())
        mpp[line] = node->val;

      if (node->left != NULL)
        q.push({node->left, line - 1});
      if (node->right != NULL)
        q.push({node->right, line + 1});
    }

    for (auto it : mpp)
      ans.push_back(it.second);

    return ans;
  }
};

void printResult(const vector<int> &result)
{
  for (auto node : result)
  {
    cout << node << " ";
  }
  cout << endl;
}

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
  vector<int> topView = solution.topView(root);

  cout << "Top View: ";
  printResult(topView);

  return 0;
}

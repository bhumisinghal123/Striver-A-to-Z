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
  int findMaxDistance(map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
  {
    queue<TreeNode *> q;
    q.push(target);
    map<TreeNode *, int> vis;
    vis[target] = 1;

    int maxi = 0;

    while (!q.empty())
    {
      int sz = q.size();
      int fl = 0;

      for (int i = 0; i < sz; i++)
      {
        auto node = q.front();
        q.pop();

        if (node->left && !vis[node->left])
        {
          fl = 1;
          vis[node->left] = 1;
          q.push(node->left);
        }

        if (node->right && !vis[node->right])
        {
          fl = 1;
          vis[node->right] = 1;
          q.push(node->right);
        }

        if (mpp[node] && !vis[mpp[node]])
        {
          fl = 1;
          vis[mpp[node]] = 1;
          q.push(mpp[node]);
        }
      }

      if (fl)
        maxi++;
    }

    return maxi;
  }

  TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
  {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res = nullptr;

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      if (node->val == start)
        res = node;

      if (node->left)
      {
        mpp[node->left] = node;
        q.push(node->left);
      }

      if (node->right)
      {
        mpp[node->right] = node;
        q.push(node->right);
      }
    }

    return res;
  }

  int timeToBurnTree(TreeNode *root, int start)
  {
    map<TreeNode *, TreeNode *> mpp;
    TreeNode *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution obj;
  cout << "Time to burn tree from node 2: " << obj.timeToBurnTree(root, 2) << endl;

  return 0;
}

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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    if (root == NULL)
    {
      return result;
    }

    queue<TreeNode *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty())
    {
      int size = nodesQueue.size();
      vector<int> row(size);
      for (int i = 0; i < size; i++)
      {
        TreeNode *node = nodesQueue.front();
        nodesQueue.pop();

        int index = (leftToRight) ? i : (size - 1 - i);

        row[index] = node->val;
        if (node->left)
        {
          nodesQueue.push(node->left);
        }
        if (node->right)
        {
          nodesQueue.push(node->right);
        }
      }
      leftToRight = !leftToRight;
      result.push_back(row);
    }
    return result;
  }
};

void printResult(const vector<vector<int>> &result)
{
  for (const auto &row : result)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  Solution solution;

  vector<vector<int>> result = solution.zigzagLevelOrder(root);

  printResult(result);
  return 0;
}
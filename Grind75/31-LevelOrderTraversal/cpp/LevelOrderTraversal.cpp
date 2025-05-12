#include "LevelOrderTraversal.h"
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using namespace BST;

vector<vector<int>> LevelOrderTraversal::levelOrder(TreeNode* root) {
  queue<pair<TreeNode*, int>> nodeStack;
  nodeStack.push(make_pair(root, 0));
  vector<vector<int>> result;

  while (!nodeStack.empty()) {
    pair<TreeNode*, int> &front = nodeStack.front();
    TreeNode *node = front.first;
    int level = front.second;
    nodeStack.pop();
    if (!node)
      continue;
    if (result.size() <= static_cast<size_t>(level))
      result.push_back({node->val});
    else
      result[level].push_back(node->val);
    nodeStack.push(make_pair(node->left, level+1));
    nodeStack.push(make_pair(node->right, level+1));
  }
  return result;
}

vector<vector<int>> LevelOrderTraversal::levelOrderRecursive(TreeNode* root) {
  vector<vector<int>> result;
  helper(root, 0, result);
  return result;
}

void LevelOrderTraversal::helper(TreeNode* node, int level, vector<vector<int>> &result) {
  if (!node)
    return;
  if (static_cast<size_t>(level) >= result.size())
    result.push_back({node->val});
  else
    result[level].push_back(node->val);
  helper(node->left, level+1, result);
  helper(node->right, level+1, result);
}


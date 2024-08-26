#include "MaxDepth.h"
#include <Tree.h>
#include <stack>
#include <utility>

using namespace BST;

int MaxDepth::maxDepth(TreeNode* root) {
  if (!root)
    return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int MaxDepth::maxDepth2(TreeNode *root) {
  if (!root)
    return 0;

  std::stack<std::pair<TreeNode*, int>> s;
  s.push(std::make_pair(root, 1));
  int maxDepth = 0;

  while (!s.empty()) {
    std::pair<TreeNode *, int> t = s.top();
    s.pop();
    TreeNode *node = t.first;
    int depth = t.second;
    if (depth > maxDepth)
      maxDepth = depth;
    if (node->left)
      s.push(std::make_pair(node->left, depth+1));
    if (node->right)
      s.push(std::make_pair(node->right, depth+1));
  }
  return maxDepth;
}


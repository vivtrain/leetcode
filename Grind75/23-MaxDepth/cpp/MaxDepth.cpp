#include "MaxDepth.h"
#include <Tree.h>

using namespace BST;

int MaxDepth::maxDepth(TreeNode* root) {
  if (!root)
    return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


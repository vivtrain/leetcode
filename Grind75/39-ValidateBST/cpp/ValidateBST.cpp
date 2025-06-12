#include "ValidateBST.h"
#include <Tree.h>
#include <optional>

using namespace std;
using namespace BST;

bool Solution::isValid(
    TreeNode *node,
    optional<int> lowerBound,
    optional<int> upperBound) {
  if (!node)
    return true;
  if ((lowerBound.has_value() && node->val <= lowerBound)
      || (upperBound.has_value() && node->val >= upperBound))
    return false;
  return isValid(node->left, lowerBound, node->val)
    && isValid(node->right, node->val, upperBound);
}

bool Solution::isValidBST(TreeNode *root) {
  if (!root)
    return true;
  return isValid(root->left, nullopt, root->val)
    && isValid(root->right, root->val, nullopt);
}


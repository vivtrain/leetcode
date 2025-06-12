#ifndef VALIDATE_B_S_T
#define VALIDATE_B_S_T

#include <Tree.h>
#include <optional>

using BST::TreeNode;
using std::optional;

class Solution {
  public:
    bool isValidBST(TreeNode *root);
  private:
    bool isValid(
        TreeNode *node,
        optional<int> lowerBound,
        optional<int> upperBound);
};

#endif


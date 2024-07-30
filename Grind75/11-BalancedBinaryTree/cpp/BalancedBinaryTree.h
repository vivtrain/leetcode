#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include <Tree.h>

class BalancedBinaryTree {
  public:
    bool isBalanced(BST::TreeNode *root);
  private:
    bool isBalanced_recurse(BST::TreeNode *root, int &leftDepth,
        int &rightDepth);
    bool differByAtMost1(int first, int second);
};

#endif


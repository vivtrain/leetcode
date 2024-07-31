#ifndef BALANCED_BINARY_TREE
#define BALANCED_BINARY_TREE

#include <Tree.h>

class BalancedBinaryTree {
  public:
    bool isBalanced(BST::TreeNode *root);
    bool isBalanced2(BST::TreeNode *root);
  private:
    bool isBalanced_recurse(BST::TreeNode *root, int &leftDepth,
        int &rightDepth);
    int height(BST::TreeNode *root);
};

#endif


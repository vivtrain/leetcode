#include "BalancedBinaryTree.h"
#include <cstdlib>

constexpr int max(const int &first, const int &second) {
  return (first > second) ? first : second;
}

bool BalancedBinaryTree::isBalanced_recurse(BST::TreeNode *root,
    int &leftDepth, int &rightDepth) {
  if (!root) {
    leftDepth = 0;
    rightDepth = 0;
    return true;
  }
  int leftLeftDepth = 0, leftRightDepth = 0;
  int rightLeftDepth = 0, rightRightDepth = 0;
  bool leftBalanced = isBalanced_recurse(root->left, leftLeftDepth,
      leftRightDepth);
  if (!leftBalanced)
    return false;
  leftDepth = max(leftLeftDepth+1, leftRightDepth+1);
  bool rightBalanced = isBalanced_recurse(root->right, rightLeftDepth,
      rightRightDepth);
  if (!rightBalanced)
    return false;
  rightDepth = max(rightLeftDepth+1, rightRightDepth+1);
  return abs(leftDepth - rightDepth) <= 1;
}

bool BalancedBinaryTree::isBalanced(BST::TreeNode *root) {
  int leftDepth = 0, rightDepth = 0;
  if (isBalanced_recurse(root, leftDepth, rightDepth))
    return abs(leftDepth - rightDepth) <= 1;
  else
    return false;
}

int BalancedBinaryTree::height(BST::TreeNode *root) {
  if (!root)
    return 0;
  int leftHeight = height(root->left);
  if (leftHeight == -1)
    return -1;
  int rightHeight = height(root->right);
  if (rightHeight == -1)
    return -1;
  if (abs(leftHeight-rightHeight) > 1)
    return -1;
  return max(leftHeight, rightHeight)+1;
}


bool BalancedBinaryTree::isBalanced2(BST::TreeNode *root) {
  return height(root) != -1;
}


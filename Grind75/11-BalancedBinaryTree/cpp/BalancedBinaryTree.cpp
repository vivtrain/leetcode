#include "BalancedBinaryTree.h"

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
  leftDepth = (leftLeftDepth > leftRightDepth) ? leftLeftDepth+1
      : leftRightDepth+1;
  bool rightBalanced = isBalanced_recurse(root->right, rightLeftDepth,
      rightRightDepth);
  if (!rightBalanced)
    return false;
  rightDepth = (rightLeftDepth > rightRightDepth) ? rightLeftDepth+1
      : rightRightDepth+1;
  return differByAtMost1(leftDepth, rightDepth);
}

bool BalancedBinaryTree::isBalanced(BST::TreeNode *root) {
  int leftDepth = 0, rightDepth = 0;
  if (isBalanced_recurse(root, leftDepth, rightDepth))
    return differByAtMost1(leftDepth, rightDepth);
  else
    return false;
}

bool BalancedBinaryTree::differByAtMost1(int first, int second) {
  int diff = first - second;
  return diff < 2 && diff > -2;
}


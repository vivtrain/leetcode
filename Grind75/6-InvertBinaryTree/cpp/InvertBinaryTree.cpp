#include "InvertBinaryTree.h"

TreeNode* InvertBinaryTree::invertTree(TreeNode *root) {
  if (root) {
    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
  }
  return root;
}


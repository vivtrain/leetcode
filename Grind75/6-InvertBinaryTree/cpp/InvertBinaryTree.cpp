#include "InvertBinaryTree.h"

BST::TreeNode* InvertBinaryTree::invertTree(BST::TreeNode *root) {
  if (root) {
    BST::TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
  }
  return root;
}


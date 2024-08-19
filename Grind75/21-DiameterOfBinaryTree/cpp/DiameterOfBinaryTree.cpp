#include "DiameterOfBinaryTree.h"
#include <Tree.h>

int DiameterOfBinaryTree::diameterOfBinaryTree(BST::TreeNode* root) {
  if (!root)
    return 0;
  int diameterLeft = diameterOfBinaryTree(root->left);
  int diameterRight = diameterOfBinaryTree(root->right);
  int diameterHere = maxDepth(root->left) + maxDepth(root->right);
  int max = (diameterLeft > diameterRight) ? diameterLeft : diameterRight;
  return (max > diameterHere) ? max : diameterHere;
}

int DiameterOfBinaryTree::maxDepth(BST::TreeNode *root) {
  if (!root)
    return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
}

int DiameterOfBinaryTree::diameterOfBinaryTree2(BST::TreeNode *root) {
  int bestSoFar = 0;
  diameterOfBinaryTree2_recurse(root, bestSoFar);
  return bestSoFar;
}

int DiameterOfBinaryTree::diameterOfBinaryTree2_recurse(BST::TreeNode *root,
    int &bestSoFar) {
  if (!root)
    return 0;
  int leftDepth = diameterOfBinaryTree2_recurse(root->left, bestSoFar);
  int rightDepth = diameterOfBinaryTree2_recurse(root->right, bestSoFar);
  int diameterHere = leftDepth + rightDepth;
  if (diameterHere > bestSoFar)
    bestSoFar = diameterHere;
  return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
}


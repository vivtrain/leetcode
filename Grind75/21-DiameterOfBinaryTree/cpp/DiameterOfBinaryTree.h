#ifndef DIAMETER_OF_BINARY_TREE
#define DIAMETER_OF_BINARY_TREE

#include <Tree.h>

class DiameterOfBinaryTree {
  public:
    int diameterOfBinaryTree(BST::TreeNode *root);
    int diameterOfBinaryTree2(BST::TreeNode *root);
    int diameterOfBinaryTree2_recurse(BST::TreeNode *root, int &bestSoFar);
    int maxDepth(BST::TreeNode *root);
  private:
};

#endif


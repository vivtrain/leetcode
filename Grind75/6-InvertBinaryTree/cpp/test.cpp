#include "InvertBinaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include "../../Utility/Tree.h"

int main() {
  InvertBinaryTree inv;
  BST::TreeNode *tree = BST::makeTree({4,2,6,1,3,5,7});
  BST::printTree(inv.invertTree(tree));
  freeTree(tree);
}


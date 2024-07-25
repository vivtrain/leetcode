#include "InvertBinaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include "../../Utility/Tree.h"

int main() {
  InvertBinaryTree inv;
  TreeNode *tree = makeTree({4,2,6,1,3,5,7});
  printTree("", inv.invertTree(tree), false);
  freeTree(tree);
}


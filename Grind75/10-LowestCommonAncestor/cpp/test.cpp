#include "LowestCommonAncestor.h"
#include <iostream>
#include <cassert>
#include <Tree.h>

int main() {
  LowestCommonAncestor soln;
  BST::TreeNode *tree = BST::makeTree({4}), *p, *q;
  BST::insertTree(tree, 6);
  BST::insertTree(tree, 2);
  p = BST::insertTree(tree, 1);
  BST::insertTree(tree, 3);
  BST::insertTree(tree, 5);
  q = BST::insertTree(tree, 7);
  BST::printTree(tree);
  BST::TreeNode *lca = soln.lowestCommonAncestor(tree, p, q);
  if (lca)
    std::cout << lca->val << std::endl;
}


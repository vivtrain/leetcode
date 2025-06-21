#include "LowestCommonAncestor.h"
#include <Tree.h>
#include <cassert>

using namespace std;
using namespace BST;

int main() {
  Solution soln;
  TreeNode *tree = bushy(3);
  printTree(tree);
  assert(soln.lowestCommonAncestor(tree, tree->left, tree->right) == tree);
  assert(soln.lowestCommonAncestor(tree, tree->left->left, tree->right) == tree);
  assert(soln.lowestCommonAncestor(tree, tree->left->left, tree->left->right) == tree->left);
}


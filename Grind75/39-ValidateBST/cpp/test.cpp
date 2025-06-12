#include "ValidateBST.h"
#include <Tree.h>
#include <cassert>

using namespace std;
using namespace BST;

int main() {
  Solution soln;
  TreeNode *b = bushy(3);
  printTree(b);
  assert(soln.isValidBST(b));
  TreeNode *t = new TreeNode(5);
  t->left = new TreeNode(1);
  t->right = new TreeNode(4);
  t->right->left = new TreeNode(3);
  t->right->right = new TreeNode(6);
  assert(!soln.isValidBST(t));
}


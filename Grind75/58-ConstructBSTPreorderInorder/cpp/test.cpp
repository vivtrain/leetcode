#include "ConstructBSTPreorderInorder.h"
#include <prettyPrint.h>
#include <Tree.h>

using namespace std;
using namespace BST;
using namespace colors;

int main() {
  Solution soln;
  vector<int> preorder {3,9,20,15,7};
  vector<int> inorder  {9,3,15,20,7};
  TreeNode *tree = soln.buildTree(preorder, inorder);
  printTree(tree);
  freeTree(tree);
}


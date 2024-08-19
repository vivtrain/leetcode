#include "DiameterOfBinaryTree.h"
#include <iostream>
#include <cassert>
#include <Tree.h>

int main() {
  using namespace std;
  using namespace BST;
  DiameterOfBinaryTree soln;
  TreeNode *tree = makeTree({7,3,2,4,1,5,6});
  printTree(tree);
  cout << soln.diameterOfBinaryTree2(tree) << endl;
}


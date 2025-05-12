#include "LevelOrderTraversal.h"
#include <cassert>
#include <vector>
#include <Tree.h>
#include <prettyPrint.h>

using namespace std;
using namespace BST;

int main() {
  LevelOrderTraversal soln;
  TreeNode *t = bushy(3);
  printTree(t);
  vector<vector<int>> result = soln.levelOrder(t);
  prettyPrint2D(result);
}


#include "BinaryTreeRightView.h"
#include <vector>
#include <Tree.h>
#include <prettyPrint.h>

using namespace std;
using namespace BST;

int main() {
  Solution soln;
  vector<TreeNode*> nodes {
                              new TreeNode(0),
                 new TreeNode(1),       new TreeNode(2),
          new TreeNode(3), nullptr, new TreeNode(4), nullptr,
    new TreeNode(5),
  };
  TreeNode *root = makeTree(nodes);
  printTree(root);
  vector<int> view = soln.rightSideView(root);
  prettyPrint(view);
}


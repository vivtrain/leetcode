#include "KthSmallestInBST.h"
#include "colors.h"
#include <prettyPrint.h>
#include <Tree.h>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;
using namespace BST;

int main() {
  Solution soln;
  vector<tuple<TreeNode*, int, int>> testCases {
    { bushyBST(3), 1, 1 },
    { bushyBST(3), 2, 2 },
    { bushyBST(3), 3, 3 },
    { bushyBST(3), 4, 4 },
    { bushyBST(3), 5, 5 },
    { bushyBST(3), 6, 6 },
    { bushyBST(3), 7, 7 },
    { BST::makeBST({4,2,6,5,3}), 1, 2 },
    { BST::makeBST({4,2,6,5,3}), 2, 3 },
    { BST::makeBST({4,2,6,5,3}), 3, 4 },
    { BST::makeBST({4,2,6,5,3}), 4, 5 },
    { BST::makeBST({4,2,6,5,3}), 5, 6 },
  };

  for (auto &[root, k, answer] : testCases) {
    colorOut(LIGHT_BLUE, k, "th smallest in:") << endl;
    printTree(root);
    int result = soln.kthSmallest(root, k);
    colorOut(result == answer ? GREEN : RED, "--> ", result, '\n') << endl;
    freeTree(root);
  }
}


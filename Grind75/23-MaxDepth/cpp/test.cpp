#include "MaxDepth.h"
#include <iostream>
#include <cassert>
#include <Tree.h>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  using namespace BST;
  MaxDepth soln;

  vector<pair<vector<int>, int>> testCases {
    {{}, 0},
    {{1}, 1},
    {{2,1}, 2},
    {{3,2,1,4,5,6}, 4},
    {{3,2,1,4,5,6}, 4},
    {{2,1,7,5,4,6,3}, 5},
  };

  for (auto test : testCases) {
    TreeNode *tree = BST::makeTree(test.first);
    int depth = test.second;
    BST::printTree(tree);
    cout << "Max depth should be " << depth << ", " << flush;
    int result = soln.maxDepth(tree);
    cout << "got " << result << endl;
    BST::freeTree(tree);
    assert(result == depth);
  }
  cout << "TESTS PASSED!" << endl;
}


#include "DiameterOfBinaryTree.h"
#include <iostream>
#include <cassert>
#include <Tree.h>
#include <Time.h>
#include <chrono>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  using namespace BST;
  DiameterOfBinaryTree soln;
  vector<pair<vector<int>, int>> testCases {
    {{}, 0},
    {{1}, 0},
    {{2,1}, 1},
    {{2,1,3}, 2},
    {{2,1,3,4}, 3},
    {{1,4,3,5,2,6}, 4},
    {{7,3,2,4,1,5,6}, 5},
  };

  for (auto test : testCases) {
    TreeNode *tree = makeTree(test.first);
    printTree(tree);
    cout << "should yield max diameter of " << test.second << flush;
    int result = soln.diameterOfBinaryTree2(tree);
    cout << ", got " << result << endl << endl;
    freeTree(tree);
    assert(result == test.second);
  }
  cout << "TESTS PASSED!\n" << endl;

  cout << "Performance testing..." << endl;
  auto start0 = Time::now();
  TreeNode *tree = bushy(20);
  double elapsed0 = Time::elapsed(start0);

  auto start1 = Time::now();
  soln.diameterOfBinaryTree(tree);
  double elapsed1 = Time::elapsed(start1);

  auto start2 = Time::now();
  soln.diameterOfBinaryTree2(tree);
  double elapsed2 = Time::elapsed(start2);

  cout << "Time spent building a big tree : " << elapsed0 << 's' << endl;
  cout << "Time spent in solution 1: " << elapsed1 << 's' << endl;
  cout << "Time spent in solution 2: " << elapsed2 << 's' << endl;
  freeTree(tree);
}


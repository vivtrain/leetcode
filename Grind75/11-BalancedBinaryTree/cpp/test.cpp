#include "BalancedBinaryTree.h"
#include <iostream>
#include <cassert>
#include <Tree.h>
#include <vector>
#include <tuple>
#include <prettyPrint.h>
#include <Time.h>

int main() {
  BalancedBinaryTree soln;
  std::vector<std::pair<std::vector<int>, bool>> testCases {
    {{},              true},
    {{4},             true},
    {{4,2},           true},
    {{4,2,6},         true},
    {{4,2,1},         false},
    {{4,2,6,1},       true},
    {{4,2,6,1,3},     true},
    {{4,2,6,1,3,0},   false},
    {{4,2,6,1,3,0,5}, true},
    {{4,2,6,5,7,9,8}, false},
    {{4,3,2,1,5,6,7}, false},
  };

  for (auto test : testCases) {
    BST::TreeNode *tree = BST::makeTree(test.first);
    BST::printTree(tree);
    std::cout << "should be " <<std::boolalpha<< test.second<<", "<<std::flush;
    bool result = soln.isBalanced2(tree);
    std::cout << "got " << std::boolalpha << result << std::endl << std::endl;
    BST::freeTree(tree);
    assert(result == test.second);
  }
  std::cout << "TESTS PASSED!" << std::endl;

  std::cout << "Stress testing..." << std::endl;
  BST::TreeNode *tree = BST::bushy(20);

  auto start = Time::now();
  soln.isBalanced(tree);
  auto elapsed = Time::elapsed(start);
  std::cout << "Took " << elapsed << " seconds" << std::endl;
  BST::freeTree(tree);
}


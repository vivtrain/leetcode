#include "BalancedBinaryTree.h"
#include <iostream>
#include <cassert>
#include <Tree.h>
#include <vector>
#include <tuple>

int main() {
  BalancedBinaryTree soln;
  std::vector<std::pair<BST::TreeNode*, bool>> testCases;
  testCases.push_back(std::make_pair(BST::makeTree({}),              true));
  testCases.push_back(std::make_pair(BST::makeTree({4}),             true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2}),           true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6}),         true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,1}),         false));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6,1}),       true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6,1,3}),     true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6,1,3,0}),   false));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6,1,3,0,5}), true));
  testCases.push_back(std::make_pair(BST::makeTree({4,2,6,5,7,9,8}), false));
  for (auto test : testCases) {
    BST::printTree(test.first);
    std::cout << "should be " << std::boolalpha << test.second<<"\n"<<std::endl;
    assert(soln.isBalanced(test.first) == test.second);
  }
  std::cout << "TESTS PASSED!" << std::endl;
}


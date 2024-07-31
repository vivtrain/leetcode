#include "BalancedBinaryTree.h"
#include <iostream>
#include <cassert>
#include <Tree.h>
#include <vector>
#include <tuple>
#include <prettyPrint.h>
#include <chrono>

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
  testCases.push_back(std::make_pair(BST::makeTree({4,3,2,1,5,6,7}), false));

  for (auto test : testCases) {
    BST::printTree(test.first);
    std::cout << "should be " << std::boolalpha << test.second<<"\n"<<std::endl;
    assert(soln.isBalanced(test.first) == test.second);
  }
  std::cout << "TESTS PASSED!" << std::endl;

  size_t N = 1, exp = 25, levels = 0, l = 1, t = 0;
  for (size_t i = 0; i < exp; i++)
    N += N;
  for (size_t n = N; n > 0; n /= 2) {
    levels++;
  }
  std::vector<int> tree(N-1);
  for (size_t i = 2; i < levels+1; i++) {
    l += l;
    for (size_t n = N/l; n < N; n+=N/l*2) {
      tree[t] = n;
      t++;
    }
  }
  std::cout << "Stress testing with N = " << N << " elements..." << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  soln.isBalanced(BST::makeTree(tree));
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
    (stop - start);
  std::cout << "Took " << duration.count()/1000. << " seconds" << std::endl;
}


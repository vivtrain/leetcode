#ifndef TREE
#define TREE

#include <vector>
#include <string>

namespace BST {

  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
  };

  void freeTree(TreeNode *root);
  TreeNode* insertTree(TreeNode *root, int val);
  TreeNode* makeTree(std::vector<int> ints);
  void printTree_recurse(std::string prefix, TreeNode *root, bool isLeft);
  void printTree(TreeNode *root);

}

#endif


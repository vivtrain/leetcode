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
  TreeNode* makeTree(const std::vector<TreeNode*> &nodes);
  TreeNode* insertBST(TreeNode *root, int val);
  TreeNode* makeBST(const std::vector<int> &values);
  TreeNode* bushyBST(int depth);
  void printTree(TreeNode *root);

}

#endif


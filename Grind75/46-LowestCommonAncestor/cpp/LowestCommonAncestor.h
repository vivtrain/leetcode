#ifndef LOWEST_COMMON_ANCESTOR
#define LOWEST_COMMON_ANCESTOR

#include <Tree.h>
#include <stack>

class Solution {
  public:
    BST::TreeNode* lowestCommonAncestor(
        BST::TreeNode* root,
        BST::TreeNode* p,
        BST::TreeNode* q);
    BST::TreeNode* lowestCommonAncestor2(
        BST::TreeNode* root,
        BST::TreeNode* p,
        BST::TreeNode* q);
  private:
    void dfs(
        BST::TreeNode *node,
        BST::TreeNode *target,
        std::stack<BST::TreeNode*> &path);
};

#endif


#ifndef LEVEL_ORDER_TRAVERSAL
#define LEVEL_ORDER_TRAVERSAL
#include <vector>
#include <Tree.h>

class LevelOrderTraversal {
  public:
    std::vector<std::vector<int>> levelOrder(BST::TreeNode* root);
    std::vector<std::vector<int>> levelOrderRecursive(BST::TreeNode* root);
  private:
    void helper(BST::TreeNode* root, int level, std::vector<std::vector<int>> &result);
};

#endif


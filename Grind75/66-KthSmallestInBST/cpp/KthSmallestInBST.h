#ifndef KTH_SMALLEST_IN_B_S_T
#define KTH_SMALLEST_IN_B_S_T

#include <Tree.h>

class Solution {
  public:
    int kthSmallest(BST::TreeNode* root, int k);
  private:
    int inOrder(const BST::TreeNode *const root, const uint k, uint &i);
};

#endif


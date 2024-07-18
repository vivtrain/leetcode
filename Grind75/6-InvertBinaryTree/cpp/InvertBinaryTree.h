#ifndef INVERT_BINARY_TREE
#define INVERT_BINARY_TREE

 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class InvertBinaryTree {
  public:
    TreeNode* invertTree(TreeNode *root);
  private:
};

#endif


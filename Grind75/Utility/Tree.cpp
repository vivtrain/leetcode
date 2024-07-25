#include "Tree.h"

void freeTree(TreeNode *root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

void insertTree(TreeNode *root, int val) {
  if (root) {
    if (val < root->val) {
      if (root->left)
        insertTree(root->left, val);
      else
        root->left = new TreeNode(val);
    } else if (val > root->val) {
      if (root->right)
        insertTree(root->right, val);
      else
        root->right = new TreeNode(val);
    }
  }
}

TreeNode* makeTree(std::vector<int> ints) {
  if (ints.empty())
    return nullptr;
  TreeNode *root = new TreeNode(ints.front());
  for (size_t index = 1; index < ints.size(); index++)
    insertTree(root, ints[index]);
  return root;
}

void printTree(std::string prefix, TreeNode *root, bool isLeft) {
  if (root) {
    std::cout << prefix << (isLeft ? "|--" : "`--") << root->val << std::endl;
    printTree(prefix + (isLeft ? "|  " : "   "), root->left, true);
    printTree(prefix + (isLeft ? "|  " : "   "), root->right, false);
  }
}


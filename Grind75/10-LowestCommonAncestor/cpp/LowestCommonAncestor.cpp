#include "LowestCommonAncestor.h"

BST::TreeNode* LowestCommonAncestor::lowestCommonAncestor(
    BST::TreeNode* root, BST::TreeNode* p, BST::TreeNode* q) {
  BST::TreeNode *node = root;
  if (!p || !q)
    return nullptr;
  while (node) {
    if (node == p)
      return p;
    if (node == q)
      return q;
    if (p->val > node->val) {
      if (!(q->val > node->val))
          return node;
      node = node->right;
    } else if (p->val < node->val) {
      if (!(q->val < node->val))
        return node;
      node = node->left;
    }
  }
  return node;
}


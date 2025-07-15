#include "KthSmallestInBST.h"

#include <Tree.h>

using namespace std;
using namespace BST;

int Solution::inOrder(
    const TreeNode *const root,
    const uint k,
    uint &i) {
  if (!root)
    return -1;
  int left = inOrder(root->left, k, i);
  if (left != -1)
    return left;
  if (i == k)
    return root->val;
  i++;
  int right = inOrder(root->right, k, i);
  if (right != -1)
    return right;
  return -1;
}

int Solution::kthSmallest(TreeNode* root, int k) {
  uint i = 1;
  return inOrder(root, k, i);
}


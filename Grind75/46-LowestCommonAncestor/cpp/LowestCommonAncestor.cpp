#include "LowestCommonAncestor.h"
#include <Tree.h>
#include <iostream>
#include <stack>

using namespace std;
using namespace BST;

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root == p || root == q)
    return root;
  TreeNode *lcaLeft  = lowestCommonAncestor(root->left,  p, q);
  TreeNode *lcaRight = lowestCommonAncestor(root->right, p, q);
  if (lcaLeft && lcaRight)
    return root;
  else
    return lcaLeft ? lcaLeft : lcaRight;
}

void Solution::dfs(TreeNode *node, TreeNode *target, stack<TreeNode*> &path) {
  if (!node || !target)
    return;
  path.push(node);
  if (node == target)
    return;
  if (node->left && path.top() != target)
    dfs(node->left, target, path);
  if (node->right && path.top() != target)
    dfs(node->right, target, path);
  if (path.top() != target)
    path.pop();
}

TreeNode* Solution::lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
  stack<TreeNode*> pPath, qPath;
  pPath.push(root);
  qPath.push(root);
  dfs(root, p, pPath);
  dfs(root, q, qPath);
  if (pPath.empty() || qPath.empty())
    return nullptr;
  while (pPath.size() != qPath.size()) {
    if (pPath.size() > qPath.size())
      pPath.pop();
    else
      qPath.pop();
  }
  while (pPath.top() != qPath.top()) {
    pPath.pop();
    qPath.pop();
  }
  return pPath.top();
}


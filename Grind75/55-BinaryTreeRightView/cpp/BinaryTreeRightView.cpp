#include "BinaryTreeRightView.h"
#include <queue>
#include <vector>
#include <Tree.h>

using namespace std;
using namespace BST;

vector<int> Solution::rightSideView(TreeNode* root) {
  vector<int> rightView;
  if (!root)
    return rightView;
  queue<TreeNode*> nodeQ;
  nodeQ.push(root);

  while (!nodeQ.empty()) {
    size_t qSize = nodeQ.size();
    TreeNode *rightMost = nullptr;
    for (size_t i = 0; i < qSize; i++) {
      TreeNode *node = nodeQ.front();
      nodeQ.pop();
      if (!node)
        continue;
      rightMost = node;
      nodeQ.push(node->left);
      nodeQ.push(node->right);
    }
    if (rightMost)
      rightView.push_back(rightMost->val);
  }

  return rightView;
}

vector<int> Solution::rightSideView2(TreeNode* root) {
  vector<int> rightView;
  if (!root)
    return rightView;
  queue<pair<TreeNode*, size_t>> nodeQ;
  nodeQ.push( {root, 0} );

  while (!nodeQ.empty()) {
    auto [node,depth] = nodeQ.front();
    nodeQ.pop();
    if (!node)
      continue;
    if (depth == rightView.size())
      rightView.push_back(node->val);
    else
      rightView[depth] = node->val;
    nodeQ.push( {node->left,  depth+1} );
    nodeQ.push( {node->right, depth+1} );
  }

  return rightView;
}


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
  queue<pair<TreeNode*, size_t>> nodeQ;
  nodeQ.push( {root, 0} );
  vector<vector<int>> levelOrder;

  while (!nodeQ.empty()) {
    auto [node,depth] = nodeQ.front();
    nodeQ.pop();
    if (!node)
      continue;
    if (depth == levelOrder.size())
      levelOrder.push_back({});
    levelOrder[depth].push_back(node->val);
    nodeQ.push( {node->left,  depth+1} );
    nodeQ.push( {node->right, depth+1} );
  }

  for (const vector<int> &level : levelOrder)
    rightView.push_back(level.back());

  return rightView;
}


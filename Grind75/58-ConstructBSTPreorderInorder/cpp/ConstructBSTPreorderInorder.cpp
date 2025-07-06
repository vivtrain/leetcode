#include "ConstructBSTPreorderInorder.h"
#include <Tree.h>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace BST;

TreeNode *build_recurse(
    const vector<int> &preorder, int index,
    const vector<int> &inorder,  int left, int right,
    const unordered_map<int, size_t> &iMap) {
  if (left > right || size_t(index) == preorder.size())
    return nullptr;
  TreeNode *root = new TreeNode(preorder[index]);
  int rootLoc = iMap.at(preorder[index]);
  root->left
    = build_recurse(preorder, index+1, inorder, left, rootLoc-1, iMap);
  root->right
    = build_recurse(preorder, index+1+rootLoc-left, inorder, rootLoc+1, right, iMap);
  return root;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, size_t> iMap;
  for (size_t i = 0; i < inorder.size(); i++)
    iMap[inorder[i]] = i;
  return build_recurse(preorder, 0, inorder, 0, inorder.size()-1, iMap);
}


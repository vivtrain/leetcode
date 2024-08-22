#include <Tree.h>
#include <iostream>
#include <vector>

namespace BST {

  void freeTree(BST::TreeNode *root) {
    if (root) {
      freeTree(root->left);
      freeTree(root->right);
      delete root;
    }
  }

  TreeNode* insertTree(TreeNode *root, int val) {
    if (root) {
      if (val < root->val) {
        if (root->left)
          return insertTree(root->left, val);
        else {
          root->left = new TreeNode(val);
          return root->left;
        }
      } else if (val > root->val) {
        if (root->right)
          return insertTree(root->right, val);
        else {
          root->right = new TreeNode(val);
          return root->right;
        }
      } else {
        return root;
      }
    } else {
      return nullptr;
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

  TreeNode* bushy(int depth) {
    size_t N = 1, exp = depth, levels = 0, l = 1, t = 0;
    for (size_t i = 0; i < exp; i++)
      N += N;
    for (size_t n = N; n > 0; n /= 2)
      levels++;
    std::vector<int> tree(N-1);
    for (size_t i = 2; i < levels+1; i++) {
      l += l;
      for (size_t n = N/l; n < N; n+=N/l*2) {
        tree[t] = n;
        t++;
      }
    }
    return makeTree(tree);
  }

  void printTree_recurse(std::string prefix, TreeNode *root, bool isLeft) {
    if (root) {
      std::cout << prefix << (isLeft ? "|--" : "`--") << root->val << std::endl;
      printTree_recurse(prefix + (isLeft ? "|  " : "   "), root->left, true);
      printTree_recurse(prefix + (isLeft ? "|  " : "   "), root->right, false);
    } else {
      std::cout << prefix << (isLeft ? "|--" : "`--") << "." << std::endl;
    }
  }
  void printTree(TreeNode *root) {
    printTree_recurse("", root, false);
  }

}



#include <Tree.h>
#include <iostream>
#include <vector>
#include <locale>

namespace BST {
  bool isUTF = std::locale("").name().find("UTF") != std::string::npos;
  std::string lpf_ = isUTF ? "├──" : "|--";
  std::string rpf_ = isUTF ? "└──" : "`--";
  std::string v_   = isUTF ? "│  " : "|  ";

  void freeTree(BST::TreeNode *root) {
    if (root) {
      freeTree(root->left);
      freeTree(root->right);
      delete root;
    }
  }

  TreeNode* insertBST(TreeNode *root, int val) {
    if (root) {
      if (val < root->val) {
        if (root->left)
          return insertBST(root->left, val);
        else {
          root->left = new TreeNode(val);
          return root->left;
        }
      } else if (val > root->val) {
        if (root->right)
          return insertBST(root->right, val);
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

  TreeNode* makeBST(const std::vector<int> &values) {
    if (values.empty())
      return nullptr;
    TreeNode *root = new TreeNode(values.front());
    for (size_t index = 1; index < values.size(); index++)
      insertBST(root, values[index]);
    return root;
  }

  TreeNode* makeTree(const std::vector<TreeNode*> &nodes) {
    const size_t nNodes = nodes.size();
    for (size_t n = 0; n < nNodes; n++) {
      TreeNode *node = nodes[n];
      if (!node)
        continue;
      size_t left  = 2*n + 1;
      size_t right = 2*n + 2;
      node->left  = (left < nNodes)  ? nodes[left]  : nullptr;
      node->right = (right < nNodes) ? nodes[right] : nullptr;
    }
    return nodes[0];
  }

  TreeNode* bushyBST(int depth) {
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
    return makeBST(tree);
  }

  void printTree_recurse(std::string prefix, TreeNode *root, bool isLeft) {
    if (root) {
      std::cout << prefix << (isLeft ? lpf_ : rpf_) << root->val << std::endl;
      printTree_recurse(prefix + (isLeft ? v_ : "   "), root->left, true);
      printTree_recurse(prefix + (isLeft ? v_ : "   "), root->right, false);
    } else {
      std::cout << prefix << (isLeft ? lpf_ : rpf_) << "." << std::endl;
    }
  }
  void printTree(TreeNode *root) {
    printTree_recurse("", root, false);
  }

}


#include "SerializeDeserializeBinaryTree.h"
#include <queue>
#include <string>
#include <Tree.h>
#include <vector>

using namespace std;
using namespace BST;

string Codec::serialize(TreeNode* root) {
  if (!root)
    return NULLSTR;
  queue<TreeNode*> nodeQ;
  nodeQ.push(root);

  string serialized = "";
  while (!nodeQ.empty()) {
    TreeNode *node = nodeQ.front();
    nodeQ.pop();
    if (!node) {
      serialized += NULLSTR + SEP;
      continue;
    }
    serialized += to_string(node->val) + SEP;
    nodeQ.push(node->left);
    nodeQ.push(node->right);
  }

  while (!isdigit(serialized.back()))
    serialized.pop_back();

  return serialized;
}

TreeNode* Codec::deserialize(string data) {
  data.push_back(',');
  vector<TreeNode*> nodes;
  string curNode = "";

  for (const char &c : data) {
    if (c == ',') {
      TreeNode *node = nullptr;
      if (curNode != NULLSTR)
        node = new TreeNode(atoi(curNode.c_str()));
      nodes.push_back(node);
      curNode.clear();
    } else {
      curNode.push_back(c);
    }
  }
  if (nodes.empty())
    return nullptr;

  vector<uint> holes(nodes.size(), 0);
  for (uint i = 0; i < nodes.size(); i++) {
    if (i > 0)
      holes[i] = holes[i-1];
    if (!nodes[i]) {
      holes[i]++;
      continue;
    }
    uint left  = 2 * (i - holes[i]) + 1;
    if (left < nodes.size())
      nodes[i]->left = nodes[left];
    uint right = 2 * (i - holes[i]) + 2;
    if (right < nodes.size())
      nodes[i]->right = nodes[right];
  }
  return nodes[0];
}


#ifndef SERIALIZE_DESERIALIZE_BINARY_TREE
#define SERIALIZE_DESERIALIZE_BINARY_TREE

#include <string>
#include <Tree.h>

class Codec {
  public:
    std::string serialize(BST::TreeNode* root);
    BST::TreeNode* deserialize(std::string data);
  private:
    const std::string EMPTY = "";
    const std::string SEP = ",";
    const std::string NULLSTR = "null";
};

#endif


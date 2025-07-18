#include "SerializeDeserializeBinaryTree.h"
#include <prettyPrint.h>
#include <string>
#include <Tree.h>

using namespace std;
using namespace BST;
using namespace colors;

int main() {
  Codec enc;
  TreeNode *t = makeTree({
    new TreeNode(1),
    new TreeNode(2), new TreeNode(3),
    nullptr, nullptr, new TreeNode(4), new TreeNode(5),
    nullptr, nullptr, nullptr, nullptr, new TreeNode(6), new TreeNode(7),
  });
  string serialized = enc.serialize(t);
  cout << "Serialized: " << serialized << endl;
  TreeNode *deserialized = enc.deserialize(serialized);
  cout << "Deserialized: " << endl;
  printTree(deserialized);
  freeTree(t);
  freeTree(deserialized);
}


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
from Tree import *

class Codec:
  def __init__(self) -> None:
    self.NULLSTR: str = 'null'
    self.SEP: str = ','

  def serialize(self, root: Optional[TreeNode]) -> str:
    def preorder(node: Optional[TreeNode], prefix: List[str]) -> None:
      if node is None:
        prefix.append(self.NULLSTR)
        return
      prefix.append(str(node.val))
      preorder(node.left, prefix)
      preorder(node.right, prefix)
    nodes: List[str] = []
    preorder(root, nodes)
    return self.SEP.join(nodes)

  def deserialize(self, data: str) -> Optional[TreeNode]:
    nodes = iter(data.split(self.SEP))
    def linkNodes() -> Optional[TreeNode]:
      nodeStr = next(nodes)
      if nodeStr == self.NULLSTR:
        return None
      node = TreeNode(int(nodeStr))
      node.left = linkNodes()
      node.right = linkNodes()
      return node
    return linkNodes()


if __name__ == '__main__':
  codec = Codec()
  t = makeTree([
    TreeNode(1),
    TreeNode(2),TreeNode(3),
    None, None, TreeNode(4),TreeNode(5),
    None, None, None, None, TreeNode(6),TreeNode(7),
  ])

  s = codec.serialize(t)
  print('Serialized: ', quote(s))
  d = codec.deserialize(s)
  print('Deserialized:')
  printTree(d)


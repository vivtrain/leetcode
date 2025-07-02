#!/bin/python3

from __future__ import annotations
from collections import deque
import sys
sys.path.append('../../Utility/python')
from typing import Deque, Optional, List, Tuple
from Tree import *

class Solution:
  def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
    if root is None:
      return []
    rightView: List[int] = []
    nodeQ: Deque[Tuple[Optional[TreeNode], int]] = deque()
    nodeQ.append( (root, 0) )
    while nodeQ:
      node, depth = nodeQ.popleft()
      if node is None:
        continue
      if depth == len(rightView):
        rightView.append(node.val)
      else:
        rightView[depth] = node.val
      nodeQ.append( (node.left,  depth + 1) )
      nodeQ.append( (node.right, depth + 1) )
    return rightView

  def rightSideView2(self, root: Optional[TreeNode]) -> List[int]:
    if root is None:
      return []
    rightView: List[int] = []
    levelOrder: List[List[int]] = []
    nodeQ: Deque[Tuple[Optional[TreeNode], int]] = deque()
    nodeQ.append( (root, 0) )
    while nodeQ:
      node, depth = nodeQ.popleft()
      if node is None:
        continue
      if depth == len(levelOrder):
        levelOrder.append([])
      levelOrder[depth].append(node.val)
      nodeQ.append( (node.left,  depth + 1) )
      nodeQ.append( (node.right, depth + 1) )
    for level in levelOrder:
      rightView.append(level[-1])
    return rightView


if __name__ == '__main__':
  soln = Solution()
  tree = makeTree([
      TreeNode(0),
      TreeNode(1), TreeNode(2),
      TreeNode(3), None, TreeNode(4), None,
      None, None, None, None, TreeNode(5),
    ]
  )

  printTree(tree)
  print(soln.rightSideView(tree))


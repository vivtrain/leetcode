#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

from typing import Optional, List
from Tree import *
from collections import deque
from PrettyPrint import *

class Solution(object):
  def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if (not root):
      return []
    queue = deque()
    result: List[List[int]] = []
    queue.appendleft((root, 0))

    while len(queue) != 0:
      node: TreeNode
      level: int
      (node, level) = queue.pop()
      if (not node):
        continue
      if len(result) <= level:
        result.append([node.val])
      else:
        result[level].append(node.val)
      queue.appendleft((node.left, level+1))
      queue.appendleft((node.right, level+1))

    return result

if __name__ == '__main__':
  soln = Solution()
  test = makeBST([4, 2, 1, 3, 6, 7])

  printTree(test)
  prettyPrint2D(soln.levelOrder(test))


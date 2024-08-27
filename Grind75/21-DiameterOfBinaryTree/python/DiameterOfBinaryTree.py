#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Optional
from Tree import *

class Solution(object):
  def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

    def diameter_recurse(root: Optional[TreeNode], best: int)\
        -> tuple[int, int]:
      if root is None:
        return (0, best)
      leftDepth, best = diameter_recurse(root.left, best)
      rightDepth, best = diameter_recurse(root.right, best)
      best = max(leftDepth + rightDepth, best)
      return max(leftDepth, rightDepth)+1, best

    _, diameter = diameter_recurse(root, 0)
    return diameter

if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ([], 0),
      ([1], 0),
      ([2,1], 1),
      ([2,1,3], 2),
      ([2,1,3,4], 3),
      ([1,4,3,5,2,6], 4),
      ]

  for test in testCases:
    tree = makeTree(test[0])
    diameter = test[1]
    printTree(tree)
    print(f'should have diameter {diameter}, got ', end='')
    result = soln.diameterOfBinaryTree(tree)
    print(result)
    assert result == diameter
  print('TESTS PASSED!')


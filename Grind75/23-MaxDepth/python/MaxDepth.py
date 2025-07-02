#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from Tree import *

class Solution(object):
  def maxDepth(self, root: Optional[TreeNode]) -> int:
    if root is None:
      return 0
    return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1


if __name__ == '__main__':
  soln = Solution()
  testCases: list[tuple[list, int]] = [
    ([], 0),
    ([1], 1),
    ([2,1], 2),
    ([2,1,3], 2),
    ([2,1,3,4], 3),
    ([2,1,7,5,4,3,6], 5),
  ]

  for lst, depth in testCases:
    tree = makeBST(lst)
    printTree(tree)
    print(f'should have a depth of {depth}, ', end='')
    res = soln.maxDepth(tree)
    print(f'got {res}')
    assert res == depth
  print('TESTS PASSED!')


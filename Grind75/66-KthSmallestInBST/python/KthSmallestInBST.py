#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
from Tree import *

class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    count: int = 0
    def inOrder(root: Optional[TreeNode]) -> Optional[int]:
      if root is None:
        return None
      left = inOrder(root.left)
      if left is not None:
        return left
      nonlocal count
      count += 1
      if count == k:
        return root.val
      right = inOrder(root.right)
      if right is not None:
        return right
      return None
    result = inOrder(root)
    return result if result is not None else count

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( makeBST([4,2,1,3,6,5,7]), 1, 1 ),
    ( makeBST([4,2,1,3,6,5,7]), 2, 2 ),
    ( makeBST([4,2,1,3,6,5,7]), 3, 3 ),
    ( makeBST([4,2,1,3,6,5,7]), 4, 4 ),
    ( makeBST([4,2,1,3,6,5,7]), 5, 5 ),
    ( makeBST([4,2,1,3,6,5,7]), 6, 6 ),
    ( makeBST([4,2,1,3,6,5,7]), 7, 7 ),
    ( makeBST([4,2,1,5,7]), 1, 1 ),
    ( makeBST([4,2,1,5,7]), 2, 2 ),
    ( makeBST([4,2,1,5,7]), 3, 4 ),
    ( makeBST([4,2,1,5,7]), 4, 5 ),
    ( makeBST([4,2,1,5,7]), 5, 7 ),
    ( makeBST([4,2,3,6,5]), 1, 2 ),
    ( makeBST([4,2,3,6,5]), 2, 3 ),
    ( makeBST([4,2,3,6,5]), 3, 4 ),
    ( makeBST([4,2,3,6,5]), 4, 5 ),
    ( makeBST([4,2,3,6,5]), 5, 6 ),
  ]

  good: bool = True
  for root, k, answer in testCases:
    colorPrint(LIGHT_BLUE, k, 'th smallest in:', sep='')
    printTree(root)
    result = soln.kthSmallest(root, k)
    colorPrint(GREEN if result == answer else RED, '-->', result, '\n')
    good = good and result == answer
  if good:
    colorPrint(GREEN, 'ALL TESTS PASSED!')
  else:
    colorPrint(RED, 'Something Failed')


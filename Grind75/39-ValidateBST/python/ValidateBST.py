#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Optional
from Tree import *
from math import inf

class Solution:
  def isValidBST(self, root: Optional[TreeNode]) -> bool:
    if root is None:
      return True
    def isValid(node: Optional[TreeNode],
                lowerBound: Optional[int],
                upperBound: Optional[int]) -> bool:
      if node is None:
        return True
      if lowerBound is not None and node.val <= lowerBound:
        return False
      if upperBound is not None and node.val >= upperBound:
        return False
      return isValid(node.left, lowerBound, node.val) \
          and isValid(node.right, node.val, upperBound)
    return isValid(root.left, None, root.val) \
        and isValid(root.right, root.val, None)

  def isValidBST2(self, root: Optional[TreeNode]) -> bool:
    if root is None:
      return True
    prev = -inf
    def isValid(node: Optional[TreeNode]) -> bool:
      if node is None:
        return True
      if not isValid(node.left):
        return False
      nonlocal prev
      if node.val <= prev:
        return False
      prev = node.val
      if not isValid(node.right):
        return False
      return True
    return isValid(root)


if __name__ == '__main__':
  soln = Solution()


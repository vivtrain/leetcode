#!/bin/python3

from __future__ import annotations
import sys

import Tree
sys.path.append('../../Utility/python')
from Tree import *

class Solution(object):
  def lowestCommonAncestor(self,
      root: Optional[TreeNode],
      p: Optional[TreeNode],
      q: Optional[TreeNode]) -> Optional[TreeNode]:
    if root is None or root is p or root is q:
      return root
    lcaLeft = self.lowestCommonAncestor(root.left, p, q)
    lcaRight = self.lowestCommonAncestor(root.right, p, q)
    if lcaLeft is not None and lcaRight is not None:
      return root
    return lcaLeft if lcaLeft is not None else lcaRight

if __name__ == '__main__':
  soln = Solution()
  testCases = []

  for test in testCases:
    pass


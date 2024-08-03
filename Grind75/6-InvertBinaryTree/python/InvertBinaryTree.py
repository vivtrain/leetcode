#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from Tree import *

class Solution(object):
  def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    if root is None:
      return None
    left = root.left
    root.left = self.invertTree(root.right)
    root.right = self.invertTree(left)
    return root



if __name__ == '__main__':
  soln = Solution()

  tree = makeTree([4,2,6,3]);
  printTree(tree)
  printTree(soln.invertTree(tree))
 
  #print('TESTS PASSED!')


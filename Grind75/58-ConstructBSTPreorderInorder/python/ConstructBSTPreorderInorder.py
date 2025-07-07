#!/bin/python3

from __future__ import annotations
import sys
from typing import Dict
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
from Tree import *

class Solution:
  def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    if len(preorder) == 0:
      return None
    iMap: Dict[int,int] = { v:i for i,v in enumerate(inorder) }
    def recurse(po: int, iol: int, ior) -> Optional[TreeNode]:
      if po >= len(preorder) or iol > ior:
        return None
      root = TreeNode(preorder[po])
      rootLoc = iMap[root.val]
      root.left  = recurse(po + 1, iol, rootLoc-1)
      root.right = recurse(po + (rootLoc-iol) + 1, rootLoc+1, ior)
      return root
    return recurse(0, 0, len(inorder)-1)

if __name__ == '__main__':
  soln = Solution()
  printTree(soln.buildTree([3,9,20,15,7],[9,3,15,20,7]))


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from Tree import *

class Solution:
  def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) \
      -> TreeNode:
    node = root
    while node is not None:
      if node is p:
        return p
      if node is q:
        return q
      if p.val > node.val:
        if not q.val > node.val:
          return node
        node = node.right
      elif p.val < node.val:
        if not q.val < node.val:
          return node
        node = node.left
    return None

if __name__ == '__main__':
  soln = Solution()

  n4 = makeBST([4])
  n2 = insertBST(n4, 2)
  n6 = insertBST(n4, 6)
  n1 = insertBST(n4, 1)
  n3 = insertBST(n4, 3)
  n5 = insertBST(n4, 5)
  n7 = insertBST(n4, 7)
  printTree(n4)

  testCases = [
      (None, None, None, None),
      (n4, n4, n4, n4),
      (n4, n2, n6, n4),
      (n4, n1, n3, n2),
      (n4, n1, n5, n4),
      ]

  success = True
  for test in testCases:
    result = soln.lowestCommonAncestor(test[0], test[1], test[2])
    if result is not test[3]:
      print('LCA of', test[1].val, 'and', test[2].val, 'resulted in',
          result.val if result is not None else None)
      success = False
    pass
  if success:
    print('TESTS PASSED!')


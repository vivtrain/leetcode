#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Optional
from List import *

class Solution(object):
  def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    node = head
    prev = None
    while node is not None:
      nxt = node.next
      node.next = prev
      prev = node
      node = nxt
    return prev

if __name__ == '__main__':
  soln = Solution()

  for n in range(10):
    fwd = list(range(n))
    rev = list(fwd)
    rev.reverse()
    print(fwd, rev)
    assert extractList(soln.reverseList(makeList(fwd))) == rev

  print('TESTS PASSED!')


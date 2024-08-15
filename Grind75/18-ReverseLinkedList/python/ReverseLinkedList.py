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

  def reverseList_recursive(self, head: Optional[ListNode]) \
      -> Optional[ListNode]:
    if head is None:
      return None
    if head.next is None:
      return head
    restTail = head.next
    rest = self.reverseList_recursive(head.next)
    restTail.next = head
    head.next = None
    return rest

if __name__ == '__main__':
  soln = Solution()

  for n in range(10):
    fwd = list(range(n))
    rev = list(fwd)
    rev.reverse()
    print(f'{fwd}, {rev} -> ', end='')
    result = extractList(soln.reverseList_recursive(makeList(fwd)))
    print(result)
    assert result == rev

  print('TESTS PASSED!')


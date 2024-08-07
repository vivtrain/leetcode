#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from List import *
from typing import Optional

class Solution:
  def hasCycle(self, head: Optional[ListNode]) -> bool:
    if head is None:
      return False
    slow = head
    fast = head.next
    while fast is not None:
      if slow is fast:
        return True
      slow = slow.next
      fast = fast.next
      if fast is None:
        break
      fast = fast.next
    return False

if __name__ == '__main__':
  soln = Solution()
  testCases = []

  lst = makeList([1,2,3])
  print(soln.hasCycle(lst))
  lst.next.next.next = lst
  print(soln.hasCycle(lst))
  
  for test in testCases:
    pass
  #print('TESTS PASSED!')


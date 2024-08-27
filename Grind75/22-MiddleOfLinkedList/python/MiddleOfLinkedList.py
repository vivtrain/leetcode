#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Optional, List, Tuple
from List import *

class Solution(object):
  def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    slow = head
    fast = head
    while fast is not None and fast.next is not None and slow is not None:
      slow = slow.next
      fast = fast.next.next
    return slow

if __name__ == '__main__':
  soln = Solution()
  testCases: List[Tuple[Optional[ListNode], Optional[ListNode]]]
  testCases = [((makeList([]), None))]

  for length in range(1,11):
    lst = makeList(list(range(length)))
    mid = atIndex(lst, length//2)
    testCases.append((lst, mid))

  for lst, mid in testCases:
    print(strList(lst), 'mid at', mid.val if mid is not None else None, end='',
        flush=True)
    result = soln.middleNode(lst)
    print(', got', result.val if result is not None else None)
    assert result is mid
  print('TESTS PASSED!')


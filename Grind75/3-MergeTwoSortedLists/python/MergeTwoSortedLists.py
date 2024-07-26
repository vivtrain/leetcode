#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from List import *

class Solution:
  def mergeTwoLists(self, list1: Optional[ListNode],
      list2: Optional[ListNode]) -> Optional[ListNode]:
    if not list1:
      return list2
    if not list2:
      return list1
    if (list1.val <= list2.val):
      list1.next = self.mergeTwoLists(list1.next, list2)
      return list1
    if (list1.val > list2.val):
      list2.next = self.mergeTwoLists(list1, list2.next)
      return list2

if __name__ == '__main__':
  soln = Solution()
  testCases = [(makeList([]), makeList([]), []),
               (makeList([1]), makeList([]), [1]),
               (makeList([]), makeList([1]), [1]),
               (makeList([1]), makeList([1]), [1]),
               (makeList([1]), makeList([2]), [1,2]),
               (makeList([2]), makeList([1]), [1,2]),
               (makeList([1,2]), makeList([3]), [1,2,3]),
               (makeList([1,2,5,6]), makeList([3,4,7,8]), [1,2,3,4,5,6,7,8]),
               ]
  for test in testCases:
    print(strList(test[0]), ', ', strList(test[1]), ' -> ', test[2], ' ==? ',
        sep='', end='')
    result = soln.mergeTwoLists(test[0], test[1])
    print(strList(result))
    assert compareLists(result, test[2])
  print('TESTS PASSED!')


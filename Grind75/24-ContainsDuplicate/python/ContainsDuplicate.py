#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class Solution(object):
  def containsDuplicate(self, nums: list[int]) -> bool:
    return len(set(nums)) != len(nums)

  def containsDuplicate2(self, nums: list[int]) -> bool:
    s = set()
    for n in nums:
      if n in s:
        return True
      else:
        s.add(n)
    return False

if __name__ == '__main__':
  soln = Solution()
  testCases: list[tuple[list[int], bool]] = [
    ([], False),
    ([1], False),
    ([1,2], False),
    ([1,2,3], False),
    ([1,2,2], True),
    ([1,2,2,1], True),
  ]

  for lst, hasDup in testCases:
    print(f'{lst} does{" not" if not hasDup else ""} have a duplicate, ', end='')
    res = soln.containsDuplicate2(lst)
    print(res)
    assert res == hasDup
  print('TESTS PASSED!')


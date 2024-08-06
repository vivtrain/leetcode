#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python/')
from List import *

class Solution:
  def search_recurse(self, nums: list[int], target: int, index: int) -> int:
    if len(nums) == 0:
      return -1
    mid = len(nums)//2
    if target > nums[mid]:
      return self.search_recurse(nums[mid+1:], target, index + mid + 1)
    elif target < nums[mid]:
      return self.search_recurse(nums[:mid], target, index)
    else:
      return index + mid

  def search(self, nums: list[int], target: int) -> int:
    return self.search_recurse(nums, target, 0)

  def search_recurse2(self, nums: list[int], target: int,
      lower: int, upper: int) -> int:
    if upper < lower:
      return -1
    if upper == lower:
      return upper if nums[upper] == target else -1
    mid = (upper - lower) // 2 + lower
    if target > nums[mid]:
      return self.search_recurse2(nums, target, mid+1, upper)
    elif target < nums[mid]:
      return self.search_recurse2(nums, target, lower, mid-1)
    else:
      return mid

  def search2(self, nums: list[int], target: int) -> int:
    return self.search_recurse2(nums, target, 0, len(nums)-1)

if __name__ == '__main__':
  soln = Solution()
  testfn = soln.search
  success = True

  for length in range(10):
    testList = list(range(length))
    print()

    print(testList, 'testing', -1)
    result = testfn(testList, -1)
    if not (result == -1):
      print('somehow found -1', '(returned ', result, ')')

    for index in testList:
      print(testList, 'testing', index, end=' ')
      result = testfn(testList, index)
      if not result == index:
        print('failed to find', index, '(returned ', result, ')')
        success = False
      else:
        print('and found')

    print(testList, 'testing', length)
    result = testfn(testList, length)
    if not (result == -1):
      print('somehow found', length, '(returned ', result, ')')

  if success:
    print('TESTS PASSED!')


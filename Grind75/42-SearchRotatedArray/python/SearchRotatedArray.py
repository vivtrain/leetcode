#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List

class Solution:
  def search(self, nums: List[int], target: int) -> int:
    if len(nums) == 0:
      return -1
    left, right = 0, len(nums)-1

    while left <= right:
      center: int = (left + right) // 2
      if nums[left] == target: return left
      if nums[right] == target: return right
      if nums[center] == target: return center
      if nums[left] < nums[center]:
        if target > nums[center] or target < nums[left]:
          left = center + 1
        else:
          right = center - 1
      else:
        if target < nums[center] or target > nums[right]:
          right = center - 1
        else:
          left = center + 1
    return -1

if __name__ == '__main__':
  soln = Solution()
  testCases = []

  for test in testCases:
    pass


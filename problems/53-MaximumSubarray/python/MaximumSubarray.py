#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List

class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    if len(nums) < 1:
      return 0
    bestSum: int = nums[0]
    prefixSum: int = nums[0]
    for i in range(1, len(nums)):
      if prefixSum < 0:
        prefixSum = 0
      if prefixSum + nums[i] > bestSum:
        bestSum = prefixSum + nums[i]
      prefixSum += nums[i]
    return bestSum


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    [ -1, 2, -1, 3, -5 ],
    [ -1, -1, -1 ],
    [  ]
  ]

  for test in testCases:
    print(test, "->", soln.maxSubArray(test))


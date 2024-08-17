#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from collections import Counter

class Solution(object):
  def majorityElement(self, nums: list[int]) -> int:
    majorityNum = nums[0]
    majorityCount = 0
    for num in nums:
      if num == majorityNum:
        majorityCount += 1
      else:
        majorityCount -= 1
        if majorityCount < 0:
          majorityNum = num
          majorityCount = 1
    return majorityNum

  def majorityElement2(self, nums: list[int]) -> int:
    numCounts = Counter(nums)
    return numCounts.most_common()[0][0]


if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ([1], 1),
      ([1,1,2], 1),
      ([1,2,2], 2),
      ([1,2,2,1,1], 1),
      ]

  for test in testCases:
    print(f'{test[0]}, {test[1]} should be majority, got ', end='')
    result = soln.majorityElement2(test[0])
    print(result)
    assert result == test[1]
  print('TESTS PASSED!')


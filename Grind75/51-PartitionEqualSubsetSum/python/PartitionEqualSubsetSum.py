#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List, Set
from PrettyPrint import *
from Colors import *

class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    totalSum: int = sum(nums)
    if totalSum % 2 == 1:
      return False
    target: int = totalSum // 2
    possibleSums: Set[int] = set([0])
    for n in nums:
      newSums: Set[int] = set()
      for ps in possibleSums:
        newSums.add(ps + n)
      possibleSums.update(newSums)
    return target in possibleSums

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [1], False ),
    ( [1,2], False ),
    ( [1,1,2], True ),
    ( [1,2,2], False ),
    ( [1,5,11,5], True ),
    ( [1,5,11,4], False ),
    ( [2,2,3,3], True ),
    ( [2,2,2,3,3], True ),
    ( [2,2,2,3,3,3], False ),
  ]

  for nums, answer in testCases:
    colorPrint(LIGHT_BLUE, nums, "=>", answer, end=' ')
    result: bool = soln.canPartition(nums)
    colorPrint(GREEN if result == answer else RED, result)


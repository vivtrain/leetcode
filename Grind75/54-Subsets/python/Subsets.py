#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List, Set, Tuple
from PrettyPrint import *
from Colors import *

class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    powerSet: List[List[int]] = [ [] ]
    for n in nums:
      nSubsetsBefore = len(powerSet)
      for s in range(nSubsetsBefore):
        subset = powerSet[s].copy()
        subset.append(n)
        powerSet.append(subset)
    return powerSet

if __name__ == '__main__':
  soln = Solution()
  testCases: List[Tuple[ List[int], List[List[int]] ]] = [
    ( [], [[]] ),
    ( [1], [[],[1]] ),
    ( [1,2], [[],[1],[2],[1,2]] ),
    ( [1,2,3], [[],[1],[2],[3],[1,2],[2,3],[1,3],[1,2,3]] ),
  ]

  for nums, answer in testCases:
    colorPrint(LIGHT_BLUE, nums)
    colorPrint(WHITE, answer)
    result = soln.subsets(nums)
    good = set([tuple(sorted(s)) for s in result]) \
        == set([tuple(sorted(s)) for s in answer])
    colorPrint(GREEN if good else RED, result)


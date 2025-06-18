#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Deque, List, Set
from collections import deque
from PrettyPrint import *
from Colors import *

class Solution(object):
  def permute(self, nums: List[int]) -> List[List[int]]:
    permutations: List[List[int]] = []
    def permute(nums: Deque[int], perm: List[int]):
      if len(nums) == 0:
        permutations.append(perm.copy())
      for _ in range(len(nums)):
        perm.append(nums.popleft())
        permute(nums, perm)
        nums.append(perm.pop())
    permute(deque(nums), [])
    return permutations

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], [[]] ),
    ( [1], [[1]] ),
    ( [1,2], [[1,2],[2,1]] ),
    ( [1,2,3], [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] ),
  ]

  for nums, permutations in testCases:
    colorPrint(LIGHT_BLUE, nums)
    colorPrint(WHITE, permutations)
    answer = set([ tuple(p) for p in permutations ])
    result = soln.permute(nums)
    setResult = set([ tuple(p) for p in result ])
    good = True
    for p in answer:
      good &= p in setResult
    print(result, color("✓", GREEN) if good else color("✗", RED))


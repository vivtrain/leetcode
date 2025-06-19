#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List

class Solution(object):
  def combine(self, n: int, k: int) -> List[List[int]]:
    combinations: List[List[int]] = []
    comb: List[int] = []

    def combine(nums: List[int], leftToChoose: int):
      if len(nums) < leftToChoose:
        return
      if leftToChoose == 0:
        combinations.append(comb[:])
        return
      # take
      n = nums.pop()
      comb.append(n)
      combine(nums, leftToChoose-1)
      comb.pop()
      nums.append(n)
      # skip
      n = nums.pop()
      combine(nums, leftToChoose)
      nums.append(n)

    combine(list(range(1,n+1)), k)
    return combinations

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( 1, 0, [] ),
    ( 1, 1, [[1]] ),
    ( 2, 1, [[1],[2]] ),
    ( 3, 2, [[1,2],[1,3],[2,3]] ),
    ( 4, 2, [[1,2],[1,3],[1,4],[2,1],[2,3],[2,4],[3,1],[3,2],[3,4]] ),
  ]

  for n, k, combinations in testCases:
    print(soln.combine(n, k))


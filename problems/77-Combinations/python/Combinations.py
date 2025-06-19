#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List
from PrettyPrint import *
from Colors import *

class Solution(object):
  def combine(self, n: int, k: int) -> List[List[int]]:
    combinations: List[List[int]] = []
    comb: List[int] = []

    def combine(nLeft: int, kLeft: int):
      if nLeft < kLeft:
        return
      if kLeft == 0:
        combinations.append(comb[:])
        return
      # take
      comb.append(nLeft)
      combine(nLeft-1, kLeft-1)
      comb.pop()
      # skip
      combine(nLeft-1, kLeft)

    combine(n, k)
    return combinations

  def combine2(self, n: int, k: int) -> List[List[int]]:
    combinations: List[List[int]] = []
    comb: List[int] = []

    def combine(nums: List[int], leftToChoose: int):
      if len(nums) < leftToChoose:
        return
      if leftToChoose == 0:
        combinations.append(comb[:])
        return
      n = nums.pop()
      # take
      comb.append(n)
      combine(nums, leftToChoose-1)
      comb.pop()
      # skip
      combine(nums, leftToChoose)
      nums.append(n)

    combine(list(range(1,n+1)), k)
    return combinations

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( 1, 0, [[]] ),
    ( 1, 1, [[1]] ),
    ( 2, 1, [[1],[2]] ),
    ( 3, 2, [[1,2],[1,3],[2,3]] ),
    ( 4, 2, [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]] ),
  ]

  for n, k, combinations in testCases:
    answer = set([tuple(sorted(c)) for c in combinations])
    result = soln.combine(n, k)
    resultSet = set([tuple(sorted(c)) for c in result])
    colorPrint(LIGHT_BLUE, n, "choose", k)
    colorPrint(WHITE, answer)
    good = GREEN if resultSet==answer and len(resultSet)==len(result) else RED
    colorPrint(good, resultSet)


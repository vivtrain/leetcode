#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List
from PrettyPrint import *
from Colors import *

class Solution(object):
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    if len(candidates) == 0 and target == 0:
      return [[]]
    elif len(candidates) == 0:
      return []
    results: List[List[int]] = []

    def combSum(index: int, leftover: int, combination: List[int] ):
      if leftover < 0 or index == len(candidates):
        return
      elif leftover == 0:
        results.append(combination.copy())
        return 
      cand = candidates[index]
      # take
      combination.append(cand)
      combSum(index, leftover - cand, combination)
      combination.pop()
      # skip
      combSum(index + 1, leftover, combination)
    
    combSum(0, target, [])
    return results

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], 0, [[]] ),
    ( [2], 1, [] ),
    ( [2], 2, [[2]] ),
    ( [2], 3, [] ),
    ( [2], 4, [[2,2]] ),
    ( [2,3], 6, [[2,2,2],[3,3]] ),
    ( [2,3,5], 8, [[2,2,2,2],[2,3,3],[3,5]] ),
  ]

  for candidates, target, answer in testCases:
    colorPrint(CYAN, candidates, ", target: ", target, sep='')
    colorPrint(WHITE, answer)
    result = soln.combinationSum(candidates, target)
    checkAnswer = set(tuple(sorted(l)) for l in answer)
    checkResult = set(tuple(sorted(l)) for l in result)
    good = color('✔ ', GREEN) if checkAnswer == checkResult else color('✘', RED)
    print(result, good)
    pass


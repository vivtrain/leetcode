#!/bin/python3

from __future__ import annotations
import sys
from typing import Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
import bisect
from math import inf

class Solution:
  def jobScheduling(self,
                    startTime: List[int],
                    endTime: List[int],
                    profit: List[int]) -> int:
    jobs: List[Tuple[int, int, int]] = sorted(zip(endTime, startTime, profit))
    cache: List[int] = [0] * (len(jobs))
    for j in range(len(jobs)):
      _,s,p = jobs[j]
      prevJob = bisect.bisect_right(jobs, (s, inf, inf)) - 1
      cache[j] = max(cache[j-1], p + cache[prevJob])
    return cache[-1] if len(cache) > 0 else 0

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], [], [], 0 ),
    ( [1], [2], [3], 3 ),
    ( [1,2], [2,3], [3,4], 7 ),
    ( [1,1], [2,3], [3,4], 4 ),
    ( [1,1,2], [2,3,3], [3,4,5], 8 ),
    ( [1,2,3,4], [4,4,4,5], [1,3,2,4], 7 ),
    ( [1,2,3,4,6], [3,5,10,6,9], [20,20,100,70,60], 150 ),
  ]

  for start, end, profit, answer in testCases:
    # jobs = list(zip(start, end, profit))
    # jobs.sort(key=lambda j: j[1])
    # for j in range(len(jobs)):
    #   s, e, p = jobs[j]
    #   colorPrint(LIGHT_BLUE, f'{j}: ({s}->{e}, {p})')
    # for j in range(len(jobs)):
    #   print('prev disjoint of', j, 'is', soln._upperBound(jobs, j))
    colorPrint(LIGHT_BLUE, start)
    colorPrint(LIGHT_BLUE, end)
    colorPrint(LIGHT_BLUE, profit, '=>', answer)
    result = soln.jobScheduling(start, end, profit)
    colorPrint(GREEN if result == answer else RED, result)


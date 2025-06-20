#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List, Tuple
from PrettyPrint import *
from Colors import *

class Solution(object):
  def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    if len(intervals) < 2:
      return intervals
    intervals.sort(key=lambda x: x[0])
    result: List[List[int]] = [intervals[0]]
    for i in range(1, len(intervals)):
      iv = intervals[i]
      prev = result[-1]
      if iv[0] <= prev[1]:
        prev[1] = max(prev[1], iv[1])
      else:
        result.append(iv)
    return result

if __name__ == '__main__':
  soln = Solution()
  testCases: List[Tuple[ List[List[int]], List[List[int]] ]] = [
    ( [], [] ),
    ( [[0,1]], [[0,1]] ),
    ( [[0,1],[2,3]], [[0,1],[2,3]] ),
    ( [[0,1],[1,2]], [[0,2]] ),
    ( [[0,1],[1,2]], [[0,2]] ),
    ( [[0,3],[1,2]], [[0,3]] ),
    ( [[1,2],[0,3]], [[0,3]] ),
  ]

  for interavls, merged in testCases:
    colorPrint(LIGHT_BLUE, interavls)
    colorPrint(WHITE, merged)
    result = soln.merge(interavls)
    setMerged = set([tuple(m) for m in merged])
    setResult = set([tuple(r) for r in result])
    colorPrint(GREEN if setResult == setMerged else RED, result)
    pass


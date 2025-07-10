#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
from math import comb

class Solution:
  def uniquePaths(self, m: int, n: int) -> int:
    if m <= 0 or n <= 0:
      return 0
    return comb(m-1 + n-1, m-1)

  def uniquePaths2(self, m: int, n: int) -> int:
    if m <= 0 or n <= 0:
      return 0
    cache: List[int] = [0] * n
    for r in range(m-1, -1, -1):
      for c in range(n-1, -1, -1):
        if r == m-1 or c == n-1:
          cache[c] = 1
        else:
          cache[c] += cache[c+1]
    return cache[0]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( 0, 0, 0 ),
    ( 1, 0, 0 ),
    ( 0, 1, 0 ),
    ( 1, 1, 1 ),
    ( 2, 1, 1 ),
    ( 1, 2, 1 ),
    ( 3, 2, 3 ),
    ( 2, 3, 3 ),
    ( 2, 3, 3 ),
    ( 4, 5, 35 ),
    ( 6, 3, 21 ),
  ]

  for m, n, answer in testCases:
    colorPrint(LIGHT_BLUE, "m: ", m, ",n: ", n, " => ", answer, sep='', end=' ')
    result = soln.uniquePaths(m, n)
    print('-->', colorString(result, GREEN if result == answer else RED))


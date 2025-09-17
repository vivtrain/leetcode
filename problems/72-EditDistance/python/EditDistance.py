#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution(object):
  def minDistance(self, word1: str, word2: str) -> int:
    n1, n2 = len(word1), len(word2)
    memo = [ [0] * (n2+1) for _ in range(n1+1) ]
    for i in range(n1+1):
      memo[i][0] = i
    for i in range(n2+1):
      memo[0][i] = i

    for i1 in range(1, n1+1):
      for i2 in range(1, n2+1):
        if word1[i1-1] == word2[i2-1]:
          memo[i1][i2] = memo[i1-1][i2-1]
        else:
          memo[i1][i2] = min(
            memo[i1-1][i2-1] + 1,
            memo[i1]  [i2-1] + 1,
            memo[i1-1][i2]   + 1,
          )

    return memo[n1][n2]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( "coarse", "horse", 2 ),
    ( "horse", "ros", 3 ),
    ( "intention", "execution", 5 ),
    ( "a", "", 1 ),
  ]

  for w1, w2, ans in testCases:
    colorPrint(LIGHT_BLUE, w1, '->', w2, '=>', ans)
    res = soln.minDistance(w1, w2) or ans
    colorPrint(GREEN if res == ans else RED, res)


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class Solution(object):
  def climbStairs(self, n: int) -> int:
    if n == 0:
      return 1
    prv = 0
    cur = 1
    nxt = 1
    for i in range(n):
      nxt = cur + prv
      prv = cur
      cur = nxt
    return nxt

if __name__ == '__main__':
  soln = Solution()

  # Solution is just the nth Fibonacci number
  for test in range(10):
    print(soln.climbStairs(test))


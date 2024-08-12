#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class Solution(object):
  bad: int
  n: int

  def isBadVersion(self, version: int) -> bool:
    assert version >= 1
    assert version <= self.n
    return version >= self.bad

  def firstBadVersion(self, n: int) -> int:
    low = 1
    high = n
    while low < high:
      mid = low + (high-low)//2
      if self.isBadVersion(mid):
        high = mid
      else:
        low = mid+1
    return low

if __name__ == '__main__':
  soln = Solution()

  N = 10
  for n in range(1, N+1):
    soln.n = n
    print(list(range(1, n+1)))
    for bad in range(1,n+1):
      soln.bad = bad
      print(f'bad should be {bad} ', end='')
      result = soln.firstBadVersion(n)
      print(f'got {result}')
      assert result == bad
    print('')

  print('TESTS PASSED!')


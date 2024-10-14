#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *

class Solution(object):
  def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
    points.sort(key=lambda p: p[0]**2 + p[1]**2)
    return points[:k]

if __name__ == '__main__':
  soln = Solution()
  testCases: list[tuple[list[list[int]], int, list[list[int]]]] = [
      ([[0,0],[1,0],[0,2],[-3,0],[0,-4]], 2, [[0,0],[1,0]]),
      ]

  success = True
  for inPoints, k, outPoints in testCases:
    print(str(inPoints), '-->', str(outPoints))
    result = soln.kClosest(inPoints, k)
    if result != outPoints:
      print('\033[31mFAIL\033[0m', '-->', str(result))
      success = False
  if success:
    print('\033[32mTESTS PASSED!\033[0m')


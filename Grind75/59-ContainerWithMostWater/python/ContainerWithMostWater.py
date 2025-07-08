#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def maxArea(self, height: List[int]) -> int:
    bestArea = 0
    left, right = 0, len(height) - 1
    while (left < right):
      area = (right - left) * min(height[left], height[right])
      if area > bestArea: bestArea = area
      if height[left] < height[right]:
        left += 1
      else:
        right -= 1
    return bestArea

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], 0 ),
    ( [1], 0 ),
    ( [1,1], 1 ),
    ( [2,1], 1 ),
    ( [1,2], 1 ),
    ( [2,2], 2 ),
    ( [2,2], 2 ),
    ( [2,4,1,3,1,2,4,1], 20 ),
    ( [1,1,6,6,1,1], 6 ),
    ( [1,1,1,6,6,1,1,1], 7 ),
    ( [1,8,6,2,5,4,8,3,7], 49 ),
  ]

  for heights, answer in testCases:
    colorPrint(LIGHT_BLUE, heights, "=>", answer, end=' ')
    result = soln.maxArea(heights)
    print('-->', end=' ')
    colorPrint(GREEN if result == answer else RED, result)

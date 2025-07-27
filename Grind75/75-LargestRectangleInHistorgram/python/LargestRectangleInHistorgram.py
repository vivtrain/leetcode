#!/bin/python3

from __future__ import annotations
import sys
from typing import Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    stack: List[Tuple[int, int]] = []
    maxArea = 0
    heights.append(-1)
    for end, height in enumerate(heights):
      start = end
      while stack and height < stack[-1][1]:
        start, h = stack.pop()
        area = h * (end - start)
        if area > maxArea:
          maxArea = area
      stack.append((start, height))
    return maxArea

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], 0 ),
    ( [1], 1 ),
    ( [1,2], 2 ),
    ( [2,1], 2 ),
    ( [2,1], 2 ),
    ( [2,1,2], 3 ),
    ( [2,1,4], 4 ),
    ( [2,1,0,2], 2 ),
    ( [2,1,4,3,1], 6 ),
    ( [2,1,4,3,1,1,1], 7 ),
    ( [2,1,2,2,2], 6 ),
    ( [3,3,3,1,3,3], 9 ),
    ( [3,1,5,6,3,4,2], 12 ),
    ( [3,6,5,7,4,8,1,0], 20 ),
  ]

  for heights, answer in testCases:
    colorPrint(LIGHT_BLUE, heights, '=>', answer)
    result = soln.largestRectangleArea(heights)
    colorPrint(GREEN if result == answer else RED, '-->', result)


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def trap2(self, height: List[int]) -> int:
    N = len(height)
    if N < 3:
      return 0
    maxLeft: List[int] = [0] * N
    maxLeft[0] = height[0]
    for h in range(1, N):
      maxLeft[h] = max(height[h], maxLeft[h-1])
    maxRight: List[int] = [0] * N
    maxRight[N-1] = height[N-1]
    for h in range(N-2, -1, -1):
      maxRight[h] = max(height[h], maxRight[h+1])
    volume = 0
    for h in range(N):
      level = min(maxLeft[h], maxRight[h])
      if level > height[h]:
        volume += level - height[h]
    return volume

  def trap(self, height: List[int]) -> int:
    left, maxLeft = 0, height[0]
    right, maxRight = len(height)-1, height[-1]
    volume = 0
    def min(a, b): return a if a < b else b
    def max(a, b): return a if a > b else b
    while (left < right):
      if height[left] < height[right]:
        water = min(maxLeft, maxRight) - height[left]
        left += 1
        maxLeft = max(height[left], maxLeft)
      else:
        water = min(maxLeft, maxRight) - height[right]
        right -= 1
        maxRight = max(height[right], maxRight)
      volume += water if water > 0 else 0
    return volume

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [0], 0 ),
    ( [1], 0 ),
    ( [0,1], 0 ),
    ( [1,0], 0 ),
    ( [1,1], 0 ),
    ( [0,1,0], 0 ),
    ( [1,0,1], 1 ),
    ( [1,0,2,1,2], 2 ),
    ( [1,0,2,1,0], 1 ),
    ( [1,0,2,0,3], 3 ),
    ( [0,1,0,2,1,0,1,3,2,1,2,1], 6 ),
    ( [4,2,0,2,5], 8 ),
    ( [4,2,0,3,2,5], 9 ),
  ]

  for height, answer in testCases:
    colorPrint(LIGHT_BLUE, height, '=>', answer, end=' ')
    result = soln.trap(height)
    colorPrint(GREEN if result == answer else RED, '-->', result)


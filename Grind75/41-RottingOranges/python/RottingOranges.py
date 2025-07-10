#!/bin/python3

from __future__ import annotations
from collections import deque
import sys
sys.path.append('../../Utility/python')
from typing import Deque, List, Tuple
from PrettyPrint import *
from Colors import *

class Solution:
  def orangesRotting(self, grid: List[List[int]]) -> int:
    # Setup
    if len(grid) == 0 or len(grid[0]) == 0:
      return 0
    nRows, nCols = len(grid), len(grid[0])
    q: Deque[Tuple[int, int, int]] = deque()
    # Find initial rotten
    for r in range(nRows):
      for c in range(nCols):
        if grid[r][c] == 2:
          q.append( (r, c, 0) )
    # Multi start bfs
    maxTime = 0
    while q:
      r, c, elapsed = q.popleft()
      maxTime = max(elapsed, maxTime)
      for row, col in [ (r-1,c), (r,c+1), (r+1,c), (r,c-1) ]:
        if row >= 0 and row < nRows and col >= 0 and col < nCols \
            and grid[row][col] == 1:
          grid[row][col] = 2
          q.append( (row, col, elapsed+1) )
    # Check for remaining oranges
    for r in range(nRows):
      for c in range(nCols):
        if grid[r][c] == 1:
          return -1
    return maxTime


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], 0 ),
    ( [[1]], -1 ),
    ( [[2]], 0 ),
    ( [[1,1]], -1 ),
    ( [[2,2]], 0 ),
    ( [[1,2]], 1 ),
    ( [[2,0,1]], -1 ),
    ( [[2,1,1]], 2 ),
    ( [[2,1,1],[1,1,0],[0,1,1]], 4 ),
    ( [[2,1,1],[1,1,0],[0,0,1]], -1 ),
    ( [[2,1,1],[0,1,1],[0,1,2]], 2 ),
  ]

  for grid, answer in testCases:
    prettyPrint2D(grid)
    print("Should take", answer, "minutes. Got ", end='')
    result = soln.orangesRotting(grid)
    print(colorString(result, GREEN) if result == answer else colorString(result, RED))
    pass

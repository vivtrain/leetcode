#!/bin/python3

from __future__ import annotations
from collections import deque
import sys
sys.path.append('../../Utility/python')
from typing import Deque, List, Tuple
from PrettyPrint import *
from Colors import *

class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    if len(grid) == 0 or len(grid[0]) == 0:
      return 0
    nRows = len(grid)
    nCols = len(grid[0])
    def markIsland(grid: List[List[str]], row: int, col: int):
      if row < 0 or col < 0 or row >= nRows or col >= nCols:
        return
      if grid[row][col] == '0' or grid[row][col] == 'X':
        return
      grid[row][col] = 'X'
      markIsland(grid, row-1, col  )
      markIsland(grid, row,   col+1)
      markIsland(grid, row+1, col  )
      markIsland(grid, row,   col-1)
    islandCount = 0
    for r in range(nRows):
      for c in range(nCols):
        if grid[r][c] == '0' or grid[r][c] == 'X':
          continue
        islandCount += 1
        markIsland(grid, r, c)
    return islandCount

  def numIslands2(self, grid: List[List[str]]) -> int:
    if len(grid) == 0 or len(grid[0]) == 0:
      return 0
    nRows = len(grid)
    nCols = len(grid[0])
    q: Deque[Tuple[int,int]] = deque()

    islandCount = 0
    for r in range(nRows):
      for c in range(nCols):
        if grid[r][c] == '0':
          continue
        islandCount += 1
        q.append((r,c))
        while q:
          r_, c_ = q.pop()
          if r_ < 0 or c_ < 0 or r_ >= nRows or c_ >= nCols:
            continue
          if grid[r_][c_] == '0':
            continue
          grid[r_][c_] = '0'
          q.append((r_-1,c_  ))
          q.append((r_,  c_+1))
          q.append((r_+1,c_  ))
          q.append((r_,  c_-1))
    return islandCount




if __name__ == '__main__':
  soln = Solution()
  testCases: List[Tuple[List[List[str]],int]] = [
    ([
      ['1','1','1','1','0'],
      ['1','1','0','1','0'],
      ['1','1','0','0','0'],
      ['0','0','0','0','0']
    ], 1),
    ([
      ['1','1','0','0','0'],
      ['1','1','0','0','0'],
      ['0','0','1','0','0'],
      ['0','0','0','1','1']
    ], 3)
  ]

  for grid, answer in testCases:
    prettyPrint2D(grid)
    print("should have", answer, "islands. Got ", end='')
    result = soln.numIslands2(grid)
    print(colorString(result, GREEN) if result == answer else colorString(result, RED))


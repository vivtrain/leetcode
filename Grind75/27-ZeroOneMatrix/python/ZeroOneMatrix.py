#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from collections import deque
from PrettyPrint import *

class Solution(object):
  def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
    rows,cols = len(mat),len(mat[0])
    coordQ: deque[tuple[int, int]] = deque()
    visited = [ [False] * cols for _ in range(rows)]

    for r in range(rows):
      for c in range(cols):
        if mat[r][c] == 0:
          coordQ.append((r,c))
          visited[r][c] = True

    while len(coordQ) != 0:
      r,c = coordQ.popleft()
      for dr,dc in [(-1,0), (0,1), (1,0), (0,-1)]:
        if (0 <= r+dr < rows) and (0 <= c+dc < cols) and not visited[r+dr][c+dc]:
          mat[r+dr][c+dc] = mat[r][c] + 1
          coordQ.append((r+dr,c+dc))
          visited[r+dr][c+dc] = True
    return mat

if __name__ == '__main__':
  soln = Solution()
  testCases: list[tuple[list[list[int]], list[list[int]]]] = [
    ([[0]], [[0]]),
    ([[0,1]], [[0,1]]),
    ([[0,1,1]], [[0,1,2]]),
    ([[0,1,1],[1,1,0],[1,1,1]], [[0,1,1],[1,1,0],[2,2,1]]),
  ]

  success = True
  for inMat,outMat in testCases:
    prettyPrint2D(inMat)
    prettyPrint2D(outMat)
    result = soln.updateMatrix(inMat)
    if result != outMat:
      print('\033[31mFAIL\033[0m')
      print('\033[91m', end='')
      prettyPrint2D(result)
      print('\033[0m', end='')
      success = False
    print()
  if success:
    print('\033[32mTESTS PASSED!\033[0m')


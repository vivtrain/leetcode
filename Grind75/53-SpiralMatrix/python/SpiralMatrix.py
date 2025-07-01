#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from typing import List, cast

class Solution:
  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    if len(matrix) == 0 or len(matrix[0]) == 0:
      return []

    VISITED = 111
    def visitable(r: int, c: int):
      return 0<=r<len(matrix) and 0<=c<len(matrix[0]) and matrix[r][c]!=VISITED

    sprialOrdered: List[int] = []
    r, c = 0, 0
    while True:
      sprialOrdered.append(matrix[r][c])
      matrix[r][c] = VISITED

      rightOK = visitable(r,   c+1)
      downOK  = visitable(r+1, c)
      leftOK  = visitable(r,   c-1)
      upOK    = visitable(r-1, c)

      if   rightOK and not upOK:    c += 1
      elif downOK  and not rightOK: r += 1
      elif leftOK  and not downOK:  c -= 1
      elif upOK    and not leftOK:  r -= 1
      else: break

    return sprialOrdered

if __name__ == '__main__':
  soln = Solution()
  matrix = [
    [ 1, 2, 3, 4],
    [12,13,14, 5],
    [11,16,15, 6],
    [10, 9, 8, 7],
  ]
  prettyPrint2D(matrix)
  print(soln.spiralOrder(matrix))



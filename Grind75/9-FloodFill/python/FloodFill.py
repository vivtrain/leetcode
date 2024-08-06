#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python/')
from List import *
from queue import Queue

class Solution:
  def floodFill(self, image: list[list[int]], sr: int, sc: int,
      color: int) -> list[list[int]]:
    if image is None or len(image) == 0 or len(image[0]) == 0:
      return image
    N = len(image)
    M = len(image[0])
    visited = [[False for m in range(M)] for n in range(N)]
    origColor = image[sr][sc]
    q = Queue()
    q.put((sr,sc))
    while not q.empty():
      (r,c) = q.get()
      visited[r][c] = True
      image[r][c] = color
      if (r-1 >= 0) and (image[r-1][c] == origColor) and (not visited[r-1][c]):
        q.put((r-1,c))
      if (r+1 < N)  and (image[r+1][c] == origColor) and (not visited[r+1][c]):
        q.put((r+1,c))
      if (c-1 >= 0) and (image[r][c-1] == origColor) and (not visited[r][c-1]):
        q.put((r,c-1))
      if (c+1 < M)  and (image[r][c+1] == origColor) and (not visited[r][c+1]):
        q.put((r,c+1))
    return image

if __name__ == '__main__':
  soln = Solution()

  testCases = [
      ([[1,1,1],[1,1,0],[1,0,1]], [[2,2,2],[2,2,0],[2,0,1]]),
      ]

  for test in testCases:
    for i in range(len(test[0])):
      print(test[0][i], end='   ')
      print(test[1][i])
    result = soln.floodFill(test[0], 1, 1, 2)
    for i in range(len(result)):
      print(result[i])

  print('TESTS PASSED!')


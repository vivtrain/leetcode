#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Optional

class Solution(object):
  def insert(self, intervals: list[list[int]], newInterval: list[int]) \
      -> list[list[int]]:
    firstOverlap: Optional[int] = None
    nOverlapped = 0
    insertLoc = 0
    def intervalsOverlap(a: list[int], b: list[int]) -> bool:
      return    b[0] <= a[0] and b[1] >= a[1] \
             or b[0] >= a[0] and b[0] <= a[1] \
             or b[1] >= a[0] and b[1] <= a[1]
    for i in range(len(intervals)):
      iv = intervals[i]
      if intervalsOverlap(iv, newInterval):
        # Overlapping
        newInterval[0] = min(newInterval[0], iv[0])
        newInterval[1] = max(newInterval[1], iv[1])
        if firstOverlap is None:
          firstOverlap = i
        nOverlapped += 1
      if newInterval[0] > iv[0]:
        insertLoc += 1
    if firstOverlap is not None:
      del intervals[firstOverlap:firstOverlap+nOverlapped]
    intervals.insert(insertLoc, newInterval)
    return intervals

  def insert2(self, intervals: list[list[int]], newInterval: list[int]) \
      -> list[list[int]]:
    i = 0
    insertLoc = 0 
    while i < len(intervals):
      if intervals[i][1] < newInterval[0]:
        i += 1
        insertLoc = i
      elif intervals[i][0] > newInterval[1]:
        i += 1
      else:
        newInterval[0] = min(newInterval[0], intervals[i][0])
        newInterval[1] = max(newInterval[1], intervals[i][1])
        del intervals[i]
    intervals.insert(insertLoc, newInterval)
    return intervals

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ([], [0,1], [[0,1]]),
    ([[0,1]], [0,1], [[0,1]]),
    ([[1,2]], [1,3], [[1,3]]),
    ([[1,2]], [0,2], [[0,2]]),
    ([[1,2]], [0,3], [[0,3]]),
    ([[1,2]], [3,4], [[1,2],[3,4]]),
    ([[3,4]], [1,2], [[1,2],[3,4]]),
    ([[1,2],[3,4],[5,6],[7,8]], [4,5], [[1,2],[3,6],[7,8]]),
    ([[1,2],[3,4],[5,6],[7,8]], [2,7], [[1,8]]),
  ]

  success = True
  for intervals, newInterval, merged in testCases:
    print(f'{intervals}, adding {newInterval}')
    print('should yield', merged)
    res = soln.insert2(intervals, newInterval)
    print('          ->', res, end='')
    if res != merged:
      success = False
      print('\033[31m FAIL\033[0m')
    else:
      print('')
  if success:
    print('\033[32mTESTS PASSED!\033[0m')


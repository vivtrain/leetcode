#!/bin/python3

from __future__ import annotations
import sys
from typing import Counter
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    counts: List[int] = []
    for _, count in Counter(tasks).items():
      counts.append(count)
    counts.sort(reverse=True)
    maxCount = 0
    for c in range(len(counts)):
      if counts[c] == counts[0]:
        maxCount += 1
      else:
        break
    return max(len(tasks), (n+1) * (counts[0] - 1) + maxCount)


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( ["A"], 2, 1 ),
    ( ["A","A"], 2, 4 ),
    ( ["A","A","B"], 3, 5 ),
    ( ["A","A","B","B"], 2, 5 ),
    ( ["A","B","B","C","C","C"], 2, 7 ),
    ( ["A","A","A","B","B","B"], 2, 8 ),
    ( ["A","B","C","D","E","A"], 3, 6 ),
  ]

  for tasks, n, answer in testCases:
    colorPrint(LIGHT_BLUE, tasks, ", ", n, " => ", answer, sep='', end='')
    result = soln.leastInterval(tasks, n)
    print(' --> ', end='')
    colorPrint(GREEN if result == answer else RED, result)


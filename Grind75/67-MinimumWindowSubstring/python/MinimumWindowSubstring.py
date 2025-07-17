#!/bin/python3

from __future__ import annotations
from collections import defaultdict
import sys
from typing import Counter, DefaultDict, Optional, Set, Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def minWindow(self, s: str, t: str) -> str:
    if len(t) > len(s) or len(s) == 0:
      return ""
    need: Counter[str] = Counter(t)
    have: DefaultDict[str, int] = defaultdict(int)
    satisfied: Set[str] = set()
    bestWin: Optional[Tuple[int,int]] = None
    start: Optional[int] = None

    for end in range(1, len(s) + 1):
      c = s[end - 1]
      if c not in need:
        continue
      if start is None:
        start = end - 1
      have[c] += 1
      if have[c] == need[c]:
        satisfied.add(c)
      if len(satisfied) == len(need):
        assert(start is not None)
        newStart = start
        nc = s[newStart]
        while newStart < end and (nc not in need or have[nc] > need[nc]):
          have[nc] -= 1
          newStart += 1
          nc = s[newStart]
        start = newStart
        if bestWin is None or (end - start) < (bestWin[1] - bestWin[0]):
          bestWin = (start, end)
    
    return s[bestWin[0]:bestWin[1]] if bestWin is not None else ""

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( "A", "AA", "" ),
    ( "AA", "A", "A" ),
    ( "AB", "C", "" ),
    ( "ABCDAB", "ABC", "ABC" ),
    ( "ABDCAB", "ABC", "CAB" ),
    ( "AABADADAC", "AABC", "BADADAC" ),
    ( "ABCADBCADBDC", "ABC", "ABC" ),
    ( "ABCADBCADBDC", "ABCD", "BCAD" ),
    ( "ABCADBCADBDC", "AABCD", "ABCAD" ),
    ( "ABCADBCADBDC", "AABCDD", "ADBCAD" ),
    ( "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc", "abc", "abc" ),
  ]

  def quot(s: str):
    return '"' + s + '"'

  for s, t, answer in testCases:
    colorPrint(LIGHT_BLUE, quot(s), ", ", quot(t), " => ", quot(answer), sep='')
    result = soln.minWindow(s, t)
    colorPrint(GREEN if result == answer else RED, quot(result))


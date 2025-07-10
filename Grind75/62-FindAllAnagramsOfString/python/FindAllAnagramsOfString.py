#!/bin/python3

from __future__ import annotations
import sys
from typing import Counter
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def findAnagrams(self, s: str, p: str) -> List[int]:
    anagrams: List[int] = []
    if len(s) == 0 or len(s) < len(p):
      return anagrams

    def ind(c: str) -> int: return ord(c) - ord('a')

    pCount = [0] * 26
    for c in p:
      pCount[ind(c)] += 1

    sCount = [0] * 26
    for i in range(len(p) - 1):
      sCount[ind(s[i])] += 1

    for start in range(len(s) - len(p) + 1):
      sCount[ind(s[start + len(p) - 1])] += 1
      if pCount == sCount:
        anagrams.append(start)
      sCount[ind(s[start])] -= 1

    return anagrams


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( "abc", "ab", [0] ),
    ( "aba", "ab", [0,1] ),
    ( "bacbacb", "abc", [0,1,2,3,4] ),
    ( "bacdbacb", "abc", [0,4,5] ),
  ]

  for s, p, answer in testCases:
    colorPrint(LIGHT_BLUE, quote(s), ", ", quote(p), " => ", answer, sep='', end='')
    print(' --> ', end='')
    result = soln.findAnagrams(s, p)
    colorPrint(GREEN if result == answer else RED, result)


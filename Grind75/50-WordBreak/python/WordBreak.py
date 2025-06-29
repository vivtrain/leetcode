#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Set
from PrettyPrint import *
from Colors import *

class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    if len(s) == 0:
      return True
    if len(wordDict) == 0:
      return False
    words: Set[str] = set(wordDict)
    maxLen = max([len(word) for word in words])
    endWords: List[bool] = [False] * (len(s)+1)
    endWords[0] = True
    for end in range(1, len(s)+1):
      for begin in range(max(end-maxLen, 0), end):
        if s[begin:end] in words and endWords[begin]:
          endWords[end] = True
          break
    return endWords[-1]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( "", [], True ),
    ( "a", [], False ),
    ( "a", ["a"], True ),
    ( "aa", ["a"], True ),
    ( "ab", ["ab"], True ),
    ( "ab", ["a","b"], True ),
    ( "catsanddog", ["cat","cats","sand","and","dog"], True ),
    ( "catsandog", ["cat","cats","sand","and","dog"], False ),
  ]

  for s, wordDict, answer in testCases:
    colorPrint(LIGHT_BLUE, s, ", ", wordDict, " => ", answer, sep='', end=' ')
    result = soln.wordBreak(s, wordDict)
    colorPrint(GREEN if result == answer else RED, result)



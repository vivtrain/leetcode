#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def longestPalindrome(self, s: str) -> str:
    if len(s) == 0:
      return ''
    bestStart, bestEnd, bestLength = 0, 0, 1
    for c in range(len(s)):
      # Odd length palindromes
      l, r = c, c
      while l >= 0 and r < len(s) and s[l] == s[r]:
        length = r - l + 1
        if length > bestLength:
          bestLength = length
          bestStart = l
          bestEnd = r
        l -= 1
        r += 1
      # Even length palindromes
      l, r = c-1, c
      while l >= 0 and r < len(s) and s[l] == s[r]:
        length = r - l + 1
        if length > bestLength:
          bestLength = length
          bestStart = l
          bestEnd = r
        l -= 1
        r += 1
    return s[bestStart:bestEnd+1]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ("", ""),
    ("a", "a"),
    ("ab", "a"),
    ("aa", "aa"),
    ("aaa", "aaa"),
    ("aaaa", "aaaa"),
    ("aaaaa", "aaaaa"),
    ("aaaaaa", "aaaaaa"),
    ("aba", "aba"),
    ("aaba", "aba"),
    ("abaa", "aba"),
    ("abba", "abba"),
    ("aabba", "abba"),
    ("abbaa", "abba"),
  ]

  for s, answer in testCases:
    def quoted(s: str): return "'" + s + "'"
    colorPrint(LIGHT_BLUE, quoted(s), "=>", quoted(answer), end=' ')
    result = soln.longestPalindrome(s)
    print('-->', end=' ')
    colorPrint(GREEN if result == answer else RED, quoted(result))


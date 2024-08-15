#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

from collections import Counter

class Solution(object):
  def longestPalindrome(self, s: str) -> int:
    letterCounts = Counter(s)
    total = 0
    anyOdd = False
    for letter, count in letterCounts.items():
      if count % 2 == 0:
        total += count
      else:
        anyOdd = True
        total += count-1
    if anyOdd:
      total += 1
    return total

if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', 0),
      ('a', 1),
      ('ab', 1),
      ('abc', 1),
      ('abcd', 1),
      ('aa', 2),
      ('aba', 3),
      ('abba', 4),
      ('abcba', 5),
      ('abccccba', 8),
      ('abbcccddddcccbba', 16),
      ('abbcccddzddcccbba', 17),
      ]

  for test in testCases:
    result = soln.longestPalindrome(test[0])
    print(f'"{test[0]}", {test[1]} -> {result}')
    assert result == test[1]
  print('TESTS PASSED!')


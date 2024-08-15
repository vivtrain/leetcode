#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

from collections import Counter

class Solution(object):
  def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    magLetters = dict()
    for c in magazine:
      if c in magLetters:
        magLetters[c] += 1
      else:
        magLetters[c] = 1
    for c in ransomNote:
      if c in magLetters:
        magLetters[c] -= 1
        if magLetters[c] < 0:
          return False
      else:
        return False
    return True

  def canConstruct2(self, ransomNote: str, magazine: str) -> bool:
    magLetters = Counter(magazine)
    noteLetters = Counter(ransomNote)

    for letter, count in noteLetters.items():
      if count > magLetters.get(letter, 0):
        return False
    return True

  def canConstruct3(self, ransomNote: str, magazine: str) -> bool:
    magLetters = Counter(magazine)
    noteLetters = Counter(ransomNote)

    if magLetters & noteLetters == noteLetters:
      return True
    return False


if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', '', True),
      ('a', 'a', True),
      ('a', 'aa', True),
      ('aa', 'a', False),
      ('ab', 'aa', False),
      ('abc', 'abbccc', True),
      ('abbc', 'abbccc', True),
      ('abbccc', 'abbccc', True),
      ('abbcccc', 'abbccc', False),
      ('abbbccc', 'abbccc', False),
      ('aabbccc', 'abbccc', False),
      ]

  for test in testCases:
    result = soln.canConstruct2(test[0], test[1])
    print(f'"{test[0]}", "{test[1]}", {test[2]} -> {result}')
    assert result == test[2]
  print('TESTS PASSED!')


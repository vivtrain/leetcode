#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python/')

class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    dictS = dict()
    for c in s:
      if not c in dictS:
        dictS[c] = 1
      else:
        dictS[c] = dictS[c] + 1
    dictT = dict()
    for c in t:
      if not c in dictT:
        dictT[c] = 1
      else:
        dictT[c] = dictT[c] + 1
    return dictS == dictT

  def isAnagram2(self, s: str, t: str) -> bool:
    return sorted(s) == sorted(t)


if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', '', True),
      ('a', '', False),
      ('a', 'a', True),
      ('a', 'aa', False),
      ('ab', 'ab', True),
      ('ab', 'ba', True),
      ('ab', 'aa', False),
      ('ab', 'ac', False),
      ('anagram', 'nagaram', True),
      ]

  for test in testCases:
    print(test[0]+',', test[1], '=>?', test[2])
    assert soln.isAnagram2(test[0], test[1]) == test[2]
  print('TESTS PASSED!')


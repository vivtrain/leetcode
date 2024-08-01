#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python/')

class Solution:
  def isPalindrome(self, s: str) -> bool:
    i = 0
    j = len(s)-1
    while i < j:
      while i < j and not s[i].isalnum():
        i = i + 1
      while i < j and not s[j].isalnum():
        j = j - 1
      if s[i].lower() != s[j].lower():
        return False
      i = i + 1
      j = j - 1
    return True

  def isPalindrome2(self, s: str) -> bool:
    converted = ''.join([c.lower() for c in s if c.isalnum()])
    n = len(converted)
    return converted[0:(n+1)//2] == converted[n//2:n][::-1]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', True),
      ('a', True),
      ('ab', False),
      ('aa', True),
      ('aba', True),
      ('ab ;a', True),
      ('abA', True),
      ('A man, a plan, a canal: Panama', True),
      ]

  for test in testCases:
    print(test[0], '=>?', test[1])
    assert soln.isPalindrome2(test[0]) == test[1]
  print('TESTS PASSED!')


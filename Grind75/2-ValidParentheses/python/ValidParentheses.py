#!/bin/python3

from __future__ import annotations
from collections import deque

class Solution:
  def isValid(self, s: str) -> bool:
    if len(s) == 0:
      return True
    delims = {'(':')', '[':']', '{':'}'}
    revDelims = {')':'(', ']':'[', '}':'{'}
    stack = deque()
    for c in s:
      if c in delims:
        stack.append(c)
      elif c in revDelims:
        if len(stack) < 1:
          return False
        top = stack[-1]
        if top != revDelims[c]:
          return False
        else:
          stack.pop()
    return len(stack) == 0

if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', True),
      ('(', False),
      ('[', False),
      ('{', False),
      (')', False),
      (']', False),
      ('}', False),
      ('()', True),
      ('[]', True),
      ('{}', True),
      ('([{}])', True),
      ('()[]{}', True),
      ('()[{]}', False),
      ('([]{}', False)]

  for test in testCases:
    print(test[0], '=>', test[1])
    assert soln.isValid(test[0]) == test[1]
  print('TESTS PASSED!')


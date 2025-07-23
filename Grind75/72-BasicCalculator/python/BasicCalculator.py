#!/bin/python3

from __future__ import annotations
import sys
from typing import Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def calculate(self, s: str) -> int:
    stack: List[Tuple[int, int]] = []
    sgn, num, sum = 1, 0, 0
    for c in s:
      match c:
        case d if c.isdigit():
          num = num * 10 + int(d)
        case '+':
          sum += sgn * num
          sgn, num = 1, 0
        case '-':
          sum += sgn * num
          sgn, num = -1, 0
        case '(':
          stack.append( (sgn, sum) )
          sgn, sum, num = 1, 0, 0
        case ')':
          sum += sgn * num
          beforeSgn, beforeSum = stack.pop()
          sum = beforeSum + beforeSgn * sum
          sgn, num = 1, 0
    sum += sgn * num
    return sum

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( "", 0 ),
    ( "1", 1 ),
    ( "(1)", 1 ),
    ( "1+2", 3 ),
    ( "1+ 2", 3 ),
    ( "1 +2", 3 ),
    ( "1 + 2", 3 ),
    ( "1 - 2", -1 ),
    ( "-1-2", -3 ),
    ( "1-2 + 3", 2 ),
    ( "-0-2", -2 ),
    ( "1 + 2 + 3", 6 ),
    ( "1 + 2 + (3 + 4)", 10 ),
    ( "1 + 2 - (3 + 4)", -4 ),
    ( "1 + 2 - (3 + (4 - 2))", -2 ),
  ]

  for s, answer in testCases:
    colorPrint(LIGHT_BLUE, quote(s), '=>', answer)
    result = soln.calculate(s)
    colorPrint(GREEN if result == answer else RED, ' -->', result)


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def myAtoi(self, s: str) -> int:
    INT_MAX: int = 2**31 - 1
    INT_MIN: int = -2**31
    sign: int = 1
    i: int = 0
    # Trim leading whitespace
    while i < len(s) and s[i].isspace(): i += 1
    if i == len(s): return 0
    # Determine sign if any
    if s[i] == '-':
      sign = -1
      i += 1
    elif s[i] == '+':
      i += 1
    if i == len(s): return 0
    # Convert to number
    start = i
    while i < len(s) and s[i].isdigit(): i += 1
    if i == start: return 0
    integer = sign * int(s[start:i])
    return max(INT_MIN, min(integer, INT_MAX))

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( '', 0 ),
    ( '-', 0 ),
    ( 'a', 0 ),
    ( '0', 0 ),
    ( '1', 1 ),
    ( ' +', 0 ),
    ( '123', 123 ),
    ( ' 123', 123 ),
    ( '   123', 123 ),
    ( '000123', 123 ),
    ( '-0123', -123 ),
    ( ' -123', -123 ),
    ( '- 123', 0 ),
    ( '+123', 123 ),
    ( '+123.4', 123 ),
    ( '123a', 123 ),
    ( '2147483647', 2147483647 ),
    ( '2147483648', 2147483647 ),
    ( '21474836470', 2147483647 ),
    ( '214748364700000000000000000000000000000000000000000000000', 2147483647 ),
    ( '000000000000000000000000000000000000000000000002147483647', 2147483647 ),
    ( '-2147483648', -2147483648 ),
    ( '-2147483649', -2147483648 ),
    ( '-21474836480', -2147483648 ),
    ( '-0000000000000000000000000000000000000000000002147483648', -2147483648 ),
  ]

  for string, integer in testCases:
    colorPrint(LIGHT_BLUE, "'"+string+"'", "=>", integer, end=" ")
    result: int = soln.myAtoi(string)
    print("-->", colorString(result, GREEN if result == integer else RED))


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List, Deque
from collections import deque
import operator

class Solution(object):
  def evalRPN(self, tokens: List[str]) -> int:
    stack: Deque[int] = deque()
    for token in tokens:
      match token:
        case "+":
          n2, n1 = stack.pop(), stack.pop()
          stack.append(n1 + n2)
        case "-":
          n2, n1 = stack.pop(), stack.pop()
          stack.append(n1 - n2)
        case "*":
          n2, n1 = stack.pop(), stack.pop()
          stack.append(n1 * n2)
        case "/":
          n2, n1 = stack.pop(), stack.pop()
          stack.append(int(n1 / n2))
        case "_":
          stack.append(int(token))
    return stack[-1]

  def evalRPN_fancy(self, tokens: List[str]) -> int:
    stack: Deque[int] = deque()
    ops = {
      "+": operator.add, "-": operator.sub,
      "*": operator.mul, "/": operator.truediv
    }
    for token in tokens:
      match token:
        case "+" | "-" | "*" | "/":
          n2, n1 = stack.pop(), stack.pop()
          stack.append(int(ops[token](n1, n2)))
        case _:
          stack.append(int(token))
    return stack.pop()

if __name__ == '__main__':
  soln = Solution()
  print(soln.evalRPN_fancy(["10","6","+"]))


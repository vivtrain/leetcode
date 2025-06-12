#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from collections import deque

class MinStack:
  def __init__(self):
    self._valstack = deque()
    self._minstack = deque()

  def push(self, val: int) -> None:
    self._valstack.append(val)
    if len(self._minstack) > 0:
      self._minstack.append(min(self.getMin(),val))
    else:
      self._minstack.append(val)

  def pop(self) -> None:
    self._valstack.pop()
    self._minstack.pop()

  def top(self) -> int:
    return self._valstack[-1]

  def getMin(self) -> int:
    return self._minstack[-1]

if __name__ == '__main__':
  ms = MinStack()
  ms.push(2)
  assert(ms.top()    == 2)
  assert(ms.getMin() == 2)
  ms.push(1)
  assert(ms.top()    == 1)
  assert(ms.getMin() == 1)
  ms.push(3)
  assert(ms.top()    == 3)
  assert(ms.getMin() == 1)



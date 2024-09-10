#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class MyQueue(object):
  enqueue: list 
  dequeue: list

  def __init__(self):
    self.enqueue = []
    self.dequeue = []

  def push(self, x: int) -> None:
    self.enqueue.append(x)

  def pop(self) -> int:
    if len(self.dequeue) == 0:
      while len(self.enqueue) > 0:
        self.dequeue.append(self.enqueue.pop())
    return self.dequeue.pop()

  def peek(self) -> int:
    if len(self.dequeue) == 0:
      while len(self.enqueue) > 0:
        self.dequeue.append(self.enqueue.pop())
    return self.dequeue[-1]

  def empty(self) -> bool:
    return len(self.enqueue) == 0 and len(self.dequeue) == 0


if __name__ == '__main__':
  soln = Solution()
  testCases = []
  
  for test in testCases:
    pass
  #print('TESTS PASSED!')


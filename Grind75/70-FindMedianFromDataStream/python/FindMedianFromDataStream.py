#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
import heapq

class MinHeap(object):
  def __init__(self) -> None:
    self.minHeap: List[int] = []
  def push(self, n: int) -> None:
    heapq.heappush(self.minHeap, n)
  def pop(self) -> int:
    return heapq.heappop(self.minHeap)
  def top(self) -> int:
    return self.minHeap[0]
  def __len__(self):
    return len(self.minHeap)

class MaxHeap(object):
  def __init__(self) -> None:
    self.maxHeap: List[int] = []
  def push(self, n: int) -> None:
    heapq.heappush(self.maxHeap, -n)
  def pop(self) -> int:
    return -heapq.heappop(self.maxHeap)
  def top(self) -> int:
    return -self.maxHeap[0]
  def __len__(self):
    return len(self.maxHeap)

class MedianFinder:
  def __init__(self):
    self.minHeap = MinHeap()
    self.maxHeap = MaxHeap()

  def addNum(self, num: int) -> None:
    if num < self.findMedian():
      self.maxHeap.push(num)
    else:
      self.minHeap.push(num)
    
    if len(self.minHeap) > len(self.maxHeap) + 1:
      self.maxHeap.push(self.minHeap.pop())
    elif len(self.maxHeap) > len(self.minHeap) + 1:
      self.minHeap.push(self.maxHeap.pop())

  def findMedian(self) -> float:
    if not self.minHeap and not self.maxHeap:
      return 0.0
    elif len(self.minHeap) > len(self.maxHeap):
      return self.minHeap.top()
    elif len(self.maxHeap) > len(self.minHeap):
      return self.maxHeap.top()
    else:
      return (self.maxHeap.top() + self.minHeap.top()) / 2

if __name__ == '__main__':
  mf = MedianFinder()

  result = mf.findMedian()
  assert(result == 0.0)

  mf.addNum(1)
  result = mf.findMedian()
  assert(result == 1.0)

  mf.addNum(2)
  result = mf.findMedian()
  assert(result == 1.5)

  mf.addNum(3)
  result = mf.findMedian()
  assert(result == 2.0)



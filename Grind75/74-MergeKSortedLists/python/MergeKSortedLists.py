#!/bin/python3

from __future__ import annotations
import sys
from typing import Optional, Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *
from List import *
from heapq import heappop, heappush

class HeapNode:
  def __init__(self, node: ListNode) -> None:
    self.node = node
  def __lt__(self, other: HeapNode) -> bool:
    return self.node.val < other.node.val

class Solution:
  def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    mergedHead, mergedTail = None, None
    minHeap: List[HeapNode] = []
    for l in lists:
      if l is not None:
        heappush(minHeap, HeapNode(l))
    while minHeap:
      node = heappop(minHeap).node
      if node.next is not None:
        heappush(minHeap, HeapNode(node.next))
      if mergedTail is None:
        mergedHead = node
        mergedTail = node
      else:
        mergedTail.next = node
        mergedTail = mergedTail.next
    return mergedHead

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [],
      [] ),
    ( [makeList([])],
      [] ),
    ( [makeList([]), makeList([])],
      [] ),
    ( [makeList([1]), makeList([])],
      [1] ),
    ( [makeList([1]), makeList([2])],
      [1,2] ),
    ( [makeList([1]), makeList([2,3])],
      [1,2,3] ),
    ( [makeList([1,3]), makeList([2])],
      [1,2,3] ),
    ( [makeList([1,3,5]), makeList([2,4,6])],
      [1,2,3,4,5,6] ),
    ( [makeList([1,3,5]), makeList([2,4,6]), makeList([0,4,7])],
      [0,1,2,3,4,4,5,6,7] ),
  ]

  for lists, answer in testCases:
    colorPrint(LIGHT_BLUE, "Merge:")
    print(LIGHT_CYAN, end='')
    for l in lists:
      printList(l)
    colorPrint(LIGHT_BLUE, "Into:")
    print(LIGHT_CYAN, end='')
    print(answer)
    result = soln.mergeKLists(lists)
    print(GREEN if compareLists(result, answer) else RED, end='')
    printList(result)
    print(NO_COLOR, end='')


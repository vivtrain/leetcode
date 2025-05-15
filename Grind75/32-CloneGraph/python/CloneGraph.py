#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

from typing import Optional, Dict, Deque
from collections import deque

class Node:
  def __init__(self, val = 0, neighbors = None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []

class Solution(object):
  def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
    if node is None:
      return None
    q: Deque[Node] = deque()
    q.append(node)
    first: Node = Node(node.val)
    cloned: Dict[Node, Node] = dict()
    cloned[node] = first

    while len(q) > 0:
      node = q.pop()
      for neighbor in node.neighbors:
        if neighbor not in cloned:
          cloned[neighbor] = Node(neighbor.val)
          q.appendleft(neighbor)
        cloned[node].neighbors.append(cloned[neighbor])
    return first

if __name__ == '__main__':
  soln = Solution()
  node1 = Node(1)
  node2 = Node(2)
  node3 = Node(3)
  node4 = Node(4)
  node1.neighbors = [node2, node4]
  node2.neighbors = [node1, node3]
  node3.neighbors = [node2, node4]
  node4.neighbors = [node1, node3]

  newGraph = soln.cloneGraph(node1)


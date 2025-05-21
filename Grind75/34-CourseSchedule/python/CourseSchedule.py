#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Deque, List, Dict, Set, Tuple
from collections import deque
from PrettyPrint import *


class Solution(object):
  def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
    # Build data structures
    adj: List[Set[int]] = [ set() for _ in range(numCourses) ]
    # toposort: List[int] = []
    toposorted: Set[int] = set()
    for edge in prerequisites:
      adj[edge[0]].add(edge[1])

    visiting: Set[int] = set()
    def finishable(node: int) -> bool:
      if node in toposorted:
        return True # already checked down this path (forward edge)
      if node in visiting:
        return False # cycle detected (backward edge)
      visiting.add(node)
      for neighbor in adj[node]:
        if not finishable(neighbor):
          return False # cycle somewhere down the line
      visiting.remove(node)
      # toposort.append(node)
      toposorted.add(node)
      return True

    for course in range(numCourses):
      if not finishable(course):
        return False

    # print(toposort)
    return len(toposorted) == numCourses

if __name__ == '__main__':
  soln = Solution()
  testCases: List[Tuple[int,List[List[int]],bool]] = [
    ( 3, [], True ),
    ( 3, [[0,0]], False ),
    ( 3, [[1,0]], True ),
    ( 3, [[1,0],[0,1]], False ),
    ( 3, [[2,1],[1,0]], True ),
    ( 3, [[2,1],[2,0]], True ),
    ( 3, [[2,1],[0,1]], True ),
    ( 3, [[2,1],[2,0]], True ),
    ( 3, [[2,1],[2,0],[1,0]], True ),
    ( 3, [[0,2],[1,2],[2,0]], False ),
    ( 3, [[1,0],[1,2],[0,1]], False ),
    ( 3, [[0,1],[1,2],[2,0]], False ),
    ( 5, [[2,0],[1,2],[1,0],[3,1],[0,3]], False ),
    ( 5, [[3,4],[3,2],[2,1],[1,4],[2,0],[1,0]], True ),
    ( 5, [[0,1],[1,2],[2,0],[0,3],[3,4],[4,0]], False ),
    ( 7, [[1,0],[0,3],[0,2],[3,2],[2,5],[4,5],[5,6],[2,4]], True ),
  ]

  for nCourses, prereqs, answer in testCases:
    print(color("TEST:", Colors.BLUE), nCourses, prereqs, "->", answer)
    result = soln.canFinish(nCourses, prereqs)
    msg = color("PASS", Colors.GREEN) if result == answer else color("FAIL", Colors.RED)
    print(msg, result)


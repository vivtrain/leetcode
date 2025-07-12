#!/bin/python3

from __future__ import annotations
from collections import defaultdict, deque
import sys
from typing import DefaultDict, Deque, Dict
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
    adj: List[List[int]] = [ [] for _ in range(n) ]
    for v1, v2 in edges:
      adj[v1].append(v2)
      adj[v2].append(v1)

    leaves: Deque[int] = deque()
    degrees: List[int] = [0] * n
    for node, neighbors in enumerate(adj):
      degrees[node] = len(neighbors)
      if len(neighbors) == 1:
        leaves.append(node)

    while leaves:
      if n <= 2:
        return list(leaves)
      for _ in range(len(leaves)):
        node = leaves.popleft()
        n -= 1
        for nbr in adj[node]:
          degrees[nbr] -= 1
          if degrees[nbr] == 1:
            leaves.append(nbr)
    
    return [0]


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( 1, [], [0]),
    ( 2, [[0,1]], [0,1] ),
    ( 3, [[0,1],[1,2]], [1] ),
    ( 4, [[0,1],[1,2],[2,3]], [1,2] ),
    ( 4, [[1,0],[1,2],[1,3]], [1] ),
    ( 5, [[0,1],[1,2],[2,3],[2,4]], [1,2] ),
  ]

  for n, edges, answer in testCases:
    colorPrint(LIGHT_BLUE, f'{n}:', prettyString2D(edges, outSep=', '),
               "=>", answer, end='')
    result = soln.findMinHeightTrees(n, edges)
    print(' --> ', end='')
    colorPrint(GREEN if set(result) == set(answer) else RED, result)


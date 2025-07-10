#!/bin/python3

from __future__ import annotations
import sys
from typing import Set, Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def exist(self, board: List[List[str]], word: str) -> bool:
    if word == '':
      return True
    elif not board or not board[0]:
      return False
    nRows, nCols = len(board), len(board[0])

    def dfs(r: int, c: int, path: Set[Tuple[int,int]]) -> bool:
      if len(path) == len(word):
        return True
      elif r < 0 or r >= nRows or c < 0 or c >= nCols \
          or (r,c) in path or board[r][c] != word[len(path)]:
        return False
      path.add((r,c))
      if  dfs(r+1, c, path) or \
          dfs(r-1, c, path) or \
          dfs(r, c+1, path) or \
          dfs(r, c-1, path):
        return True
      path.remove((r,c))
      return False

    for r in range(nRows):
      for c in range(nCols):
        path: Set[Tuple[int,int]] = set()
        if dfs(r, c, path):
          return True

    return False

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], '', True ),
    ( [[]], '', True ),
    ( [[]], 'A', False ),
    ( [['A','B','C','D'],
       ['A','B','C','D'],
       ['A','B','C','D'],
       ], 'ABCD', True ),
    ( [['A','B','C','D'],
       ['A','B','C','D'],
       ['A','B','C','D'],
       ], 'AAA', True ),
    ( [['A','B','C','D'],
       ['A','B','C','D'],
       ['A','B','C','D'],
       ], 'AAAA', False ),
    ( [['C','B','C','D'],
       ['B','A','B','E'],
       ['C','B','C','F'],
       ], 'ABCD', True ),
    ( [['C','B','C','D'],
       ['B','A','B','E'],
       ['C','B','C','F'],
       ], 'ABCE', False ),
    ( [['C','B','C','D'],
       ['B','A','B','E'],
       ['C','B','C','F'],
       ], 'ABCBCD', True ),
    ( [['C','B','C','D'],
       ['B','A','B','E'],
       ['C','B','C','F'],
       ], 'ABCBCBCBCDEF', True ),
    ( [['C','B','C','D'],
       ['B','A','B','E'],
       ['C','B','C','F'],
       ], 'ABCBCBCBCDEFC', False ),
  ]

  for board, word, answer in testCases:
    colorPrint(LIGHT_BLUE, prettyString2D(board), word, answer, sep=', ')
    print(' --> ', end='')
    result = soln.exist(board, word)
    colorPrint(GREEN if result == answer else RED, result)


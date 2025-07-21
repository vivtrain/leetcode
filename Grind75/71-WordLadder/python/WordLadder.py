#!/bin/python3

from __future__ import annotations
from collections import deque
import sys
from typing import Deque, Set, Tuple
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
    wordSet: Set[str] = set(wordList)
    if endWord not in wordSet or beginWord == endWord:
      return 0
    bfs: Deque[Tuple[str, int]] = deque()
    bfs.append( (beginWord, 0) )
    while bfs:
      word, dist = bfs.popleft()
      dist += 1
      if word == endWord:
        return dist
      wl = list(word)
      for c in range(len(word)):
        orig = wl[c]
        for l in 'abcdefghijklmnopqrstuvwxyz':
          wl[c] = l
          newWord = ''.join(wl)
          if newWord in wordSet:
            bfs.append( (newWord, dist) )
            wordSet.remove(newWord)
        wl[c] = orig
    return 0

if __name__ == '__main__':
  soln = Solution()

  print(soln.ladderLength('hit', 'cog', ["hot","dot","dog","lot","log","cog"]))


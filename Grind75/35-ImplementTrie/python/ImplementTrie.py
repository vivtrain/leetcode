#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Dict

class Trie:
  def __init__(self):
    self.isLeaf: bool = False
    self.next: Dict[str,Trie] = dict()

  def insert(self, word: str) -> None:
    if len(word) < 1:
      return
    letter = word[0]
    if letter not in self.next:
      self.next[letter] = Trie()
    if len(word) == 1:
      self.next[letter].isLeaf = True
    else:
      self.next[letter].insert(word[1:])

  def search(self, word: str) -> bool:
    if len(word) < 1:
      return True
    letter = word[0]
    if letter not in self.next:
      return False
    if len(word) == 1:
      return self.next[letter].isLeaf
    else:
      return self.next[letter].search(word[1:])

  def startsWith(self, prefix: str) -> bool:
    if len(prefix) < 1:
      return True
    letter = prefix[0]
    if letter not in self.next:
      return False
    return self.next[letter].startsWith(prefix[1:])

class Trie2:
  def __init__(self):
    self.isLeaf: bool = False
    self.next: Dict[str,Trie2] = dict()

  def insert(self, word: str) -> None:
    node: Trie2 = self
    for c in word:
      if not c in node.next:
        node.next[c] = Trie2()
      node = node.next[c]
    node.isLeaf = True

  def search(self, word: str) -> bool:
    node: Trie2 = self
    for c in word:
      if c not in node.next:
        return False
      node = node.next[c]
    return node.isLeaf

  def startsWith(self, prefix: str) -> bool:
    node: Trie2 = self
    for c in prefix:
      if c not in node.next:
        return False
      node = node.next[c]
    return True


if __name__ == '__main__':
  t: Trie2 = Trie2()
  t.insert('ab')
  assert t.startsWith('')
  assert t.startsWith('a')
  assert t.startsWith('ab')
  assert not t.startsWith('abc')


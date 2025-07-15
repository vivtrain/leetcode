#!/bin/python3

from __future__ import annotations
import sys
from typing import Dict, Optional
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class LRUCache:
  class Node:
    def __init__(self, key=-1, value=0, next=None, prev=None) -> None:
      self.key: int = key
      self.value: int = value
      self.next: Optional[LRUCache.Node] = next
      self.prev: Optional[LRUCache.Node] = prev

  def __init__(self, capacity: int):
    self.capacity: int = capacity
    self.size: int = 0
    self.lookup: Dict[int, LRUCache.Node] = {}
    self.lru: Optional[LRUCache.Node] = None
    self.mru: Optional[LRUCache.Node] = None

  def _evictLRU(self) -> None:
    assert(self.lru is not None)
    self.lookup.pop(self.lru.key)
    prev = self.lru.prev
    if prev is not None:
      prev.next = None
      self.lru = prev
    else: # evict from LRU side (tail)
      self.lru = None
      self.mru = None
      pass
    self.size -= 1

  def _insert(self, key: int, value: int) -> None:
    # Create Node
    node = LRUCache.Node(key, value)
    # Evict if at capacity
    if self.size == self.capacity:
      self._evictLRU()
    # Insert at MRU side (head)
    if self.mru is None:
      self.lru = node # cache was empty => lru now exists
    else:
      self.mru.prev = node # existing mru => update its prev
    node.next = self.mru
    self.mru = node
    self.lookup[key] = node
    self.size += 1

  def _update(self, key: int, value: int) -> None:
    assert(self.mru is not None)
    assert(self.lru is not None)
    assert(key in self.lookup)
    node = self.lookup[key]
    node.value = value
    prev, next = node.prev, node.next
    if prev is None: # i.e. node is self.mru => no change needed
      return
    elif next is None: # i.e. node is self.lru
      prev.next = None
      self.lru = prev
    else:
      prev.next = next
      next.prev = prev
    node.next = self.mru
    node.prev = None
    self.mru.prev = node
    self.mru = node

  def get(self, key: int) -> int:
    if key in self.lookup:
      value = self.lookup[key].value
      self._update(key, value)
      return value
    else:
      return -1

  def put(self, key: int, value: int) -> None:
    if key in self.lookup:
      self._update(key, value)
    else:
      self._insert(key, value)

  def print(self) -> None:
    node = self.mru
    colorPrint(GRAY, "MRU -> LRU: ", end='')
    while node:
      print(f'(k:{node.key},v:{node.value}) -> ', end='')
      node = node.next
    print()
    node = self.lru
    colorPrint(GRAY, "LRU -> MRU: ", end='')
    while node:
      print(f'(k:{node.key},v:{node.value}) -> ', end='')
      node = node.prev
    print()

if __name__ == '__main__':
  cache = LRUCache(2)
  colorPrint(LIGHT_BLUE, 'Init')
  cache.print()

  colorPrint(LIGHT_BLUE, 'Put 1')
  cache.put(1,1)
  cache.print()

  colorPrint(LIGHT_BLUE, 'Put 2')
  cache.put(2,2)
  cache.print()

  colorPrint(LIGHT_BLUE, 'Put 3')
  cache.put(3,3)
  cache.print()

  colorPrint(LIGHT_BLUE, 'Get 2')
  result = cache.get(2)
  print("Got: ", end='')
  colorPrint(GREEN if result == 2 else RED, result)
  cache.print()


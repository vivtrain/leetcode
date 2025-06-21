#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List, Dict, Tuple

class TimeMap:
    def __init__(self):
      self._tm: Dict[ str, List[Tuple[str,int]] ] = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
      if key not in self._tm:
        self._tm[key] = []
      self._tm[key].append(( value, timestamp ))

    def get(self, key: str, timestamp: int) -> str:
      if key not in self._tm:
        return ""
      values = self._tm[key]
      if timestamp < values[0][1]:
        return ""
      elif timestamp > values[-1][1]:
        return values[-1][0]
      left, right = 0, len(values)-1
      while left <= right:
        center = (left + right) // 2
        ts = values[center][1]
        if timestamp < ts:
          right = center - 1
        elif timestamp > ts:
          left = center + 1
        else:
          return values[center][0]
      return values[right][0]


if __name__ == '__main__':
  def quot(s: str): return "'" + s + "'"
  tm = TimeMap()
  tm.set("key", "LOW", 1)
  tm.set("key", "HIGH", 3)
  for i in range(5):
    print(i, quot(tm.get("key", i)))


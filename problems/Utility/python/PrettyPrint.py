from __future__ import annotations
from typing import Any

def prettyPrint2D(mat: list[list[Any]]) -> None:
  print('[[' + ']\n ['.join([', '.join([str(cell) for cell in row]) for row in mat]) + ']]')


from typing import Any, List
import Colors

def color(input: Any, color: str) -> str:
  return color + str(input) + Colors.NO_COLOR

def prettyPrint2D(mat: List[List[Any]]) -> None:
  print('[[' + ']\n ['.join([', '.join([str(cell) for cell in row]) for row in mat]) + ']]')


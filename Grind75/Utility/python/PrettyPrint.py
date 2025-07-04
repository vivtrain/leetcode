from typing import Any, List
import Colors

def color(input: Any, color: str) -> str:
  return color + str(input) + Colors.NO_COLOR

def colorPrint(color: str, *args, end='\n', sep=' '):
  print(color, sep='', end='')
  for a in range(len(args)-1):
    print(args[a], sep='', end=sep)
  if len(args) > 0:
    print(args[-1], sep='', end='')
  print(Colors.NO_COLOR, sep='', end=end)

def prettyPrint2D(mat: List[List[Any]]) -> None:
  print('[[' + ']\n ['.join([', '.join([str(cell) for cell in row]) for row in mat]) + ']]')


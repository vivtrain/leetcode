from typing import Any, List
import Colors

def color(input: Any, color: str) -> str:
  return color + str(input) + Colors.NO_COLOR

def colorPrint(color: str, *args, **kwargs):
  if 'sep' not in kwargs:
    kwargs['sep'] = ' '
  if 'end' not in kwargs:
    kwargs['end'] = '\n'
  print(color, end='')
  for a in args:
    print(a, end=kwargs['sep'])
  print(Colors.NO_COLOR, end=kwargs['end'])

def prettyPrint2D(mat: List[List[Any]]) -> None:
  print('[[' + ']\n ['.join([', '.join([str(cell) for cell in row]) for row in mat]) + ']]')


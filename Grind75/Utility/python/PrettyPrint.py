from typing import Any, List
import Colors

def quote(s: str, delim="''") -> str:
  return delim[0] + s + delim[1]

def colorPrint(color: str, *args, end='\n', sep=' '):
  print(color, sep='', end='')
  for a in range(len(args)-1):
    print(args[a], sep='', end=sep)
  if len(args) > 0:
    print(args[-1], sep='', end='')
  print(Colors.NO_COLOR, sep='', end=end)

def colorString(input: Any, color: str) -> str:
  return color + str(input) + Colors.NO_COLOR

def prettyPrint2D(
    mat: List[List[Any]],
    outSep=',\n ', inSep=', ',
    end='\n') -> None:
  print(prettyString2D(mat, outSep=outSep, inSep=inSep), end=end)

def prettyString2D(
    mat: List[List[Any]],
    outSep=',\n ', inSep=', ',
    end='') -> str:
  outSep = ']' + outSep + '['
  return '[[' \
      + outSep.join([inSep.join([str(cell) for cell in row]) for row in mat]) \
      + ']]' + end


#!/bin/python3

from __future__ import annotations
import sys
from typing import Dict
sys.path.append('../../Utility/python')
from PrettyPrint import *
from Colors import *

class Solution:
  def letterCombinations(self, digits: str) -> List[str]:
    if digits == '':
      return []
    digitLetters: Dict[str, str] = {
                    '2':'abc', '3':'def', 
        '4':'ghi',  '5':'jkl', '6':'mno',
        '7':'pqrs', '8':'tuv', '9':'wxyz',
    }
    combinations: List[str] = ['']
    for digit in digits:
      letters = digitLetters[digit]
      newCombs: List[str] = []
      for comb in combinations:
        for letter in letters:
          newCombs.append(comb + letter)
      combinations = newCombs
    return combinations


if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( '', [] ),
    ( '2', ['a','b','c',] ),
    ( '27', ['ap','bp','cp','aq','bq','cq','ar','br','cr','as','bs','cs',] ),
  ]

  for digits, answer in testCases:
    colorPrint(LIGHT_BLUE, digits)
    colorPrint(WHITE, answer)
    result = soln.letterCombinations(digits)
    colorPrint(GREEN if set(result) == set(answer) else RED, result)


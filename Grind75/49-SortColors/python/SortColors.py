#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import List
from PrettyPrint import *
from Colors import *

class Solution:
  def sortColors(self, nums: List[int]) -> None:
    left, index, right = 0, 0, len(nums) - 1
    while index <= right:
      if nums[index] == 0:
        nums[index], nums[left] = nums[left], nums[index]
        left += 1
      elif nums[index] == 2:
        nums[index], nums[right] = nums[right], nums[index]
        right -= 1
      if index < left or nums[index] == 1:
        index += 1

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ( [], [] ),
    ( [1], [1] ),
    ( [1,2], [1,2] ),
    ( [2,1], [1,2] ),
    ( [0,2], [0,2] ),
    ( [2,0], [0,2] ),
    ( [0,1,2], [0,1,2] ),
    ( [0,2,1], [0,1,2] ),
    ( [1,0,2], [0,1,2] ),
    ( [1,2,0], [0,1,2] ),
    ( [2,0,1], [0,1,2] ),
    ( [2,1,0], [0,1,2] ),
    ( [2,0,2,1,1,0], [0,0,1,1,2,2] ),
  ]

  for nums, answer in testCases:
    colorPrint(LIGHT_BLUE, nums)
    colorPrint(WHITE, answer)
    soln.sortColors(nums)
    colorPrint(GREEN if nums == answer else RED, nums)


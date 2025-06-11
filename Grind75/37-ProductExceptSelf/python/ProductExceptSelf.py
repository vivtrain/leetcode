#!/bin/python3

from __future__ import annotations
import sys

sys.path.append('../../Utility/python')
from typing import List
from PrettyPrint import color
from Colors import *

class Solution(object):
  def productExceptSelf(self, nums: List[int]) -> List[int]:
    N: int = len(nums)
    if N < 2:
      return []
    prodExceptSelf: List[int] = [ 1 ] * N
    for i in range(1, N, 1):
      prodExceptSelf[i] = prodExceptSelf[i-1] * nums[i-1]
    prodsBackward = 1
    for i in range(N-1, -1, -1):
      prodExceptSelf[i] *= prodsBackward
      prodsBackward *= nums[i]
    return prodExceptSelf

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ([], []),
    ([1], []),
    ([1,2], [2,1]),
    ([1,2,3], [6,3,2]),
    ([-1,2,3], [6,-3,-2]),
    ([0,2,3], [6,0,0]),
    ([3,2,4,-1,-5], [40,60,30,-120,-24]),
  ]

  for nums, answer in testCases:
    print(color("test:", LIGHT_BLUE), nums)
    print("       =>", answer)
    result = soln.productExceptSelf(nums)
    print(color("       ->", LIGHT_YELLOW), result, end=' ')
    if result == answer:
      print(color("PASS", GREEN))
    else:
      print(color("FAIL", RED))


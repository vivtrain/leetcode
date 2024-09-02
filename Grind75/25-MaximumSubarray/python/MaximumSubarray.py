#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class Solution(object):
  def maxSubArray(self, nums: list[int]) -> int:
    if len(nums) < 1:
      return 0
    sumBefore = 0
    bestSum = nums[0]
    for n in nums:
      if sumBefore < 0:
        sumBefore = 0
      if sumBefore + n > bestSum:
        bestSum = sumBefore + n
      sumBefore += n
    return bestSum

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    ([1], 1),
    ([-1], -1),
    ([1,2,3], 6),
    ([1,-2,3], 3),
    ([2,-1,3], 4),
    ([-2,-1,-3], -1),
    ([-2,1,-3,4,-1,2,1,-5,4], 6),
    ([-1,-2,-2,-2,3,2,-2,0], 5),
    ([1,2,-1,-2,2,1,-2,1], 3),
  ]

  success = True
  for lst, max in testCases:
    print(f'{lst} => {max}  -->  ', end='')
    res = soln.maxSubArray(lst)
    print(res, end='')
    if res != max:
      success = False
      print(' \033[91mFAIL\033[0m')
    else:
      print('')
  if success:
    print('\033[92mTESTS PASSED!\033[0m')


#!/bin/python3

from __future__ import annotations
import sys
from typing import List, Tuple
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

  def maxSubArray_DnC(self, nums: List[int]) -> int:
    def msa(lst: List[int], start: int, end: int) -> int:
      if start == end:
        return lst[start]
      center = (end + start) // 2
      leftSum, rightSum, runningSum = lst[center], lst[center+1], 0
      for l in range(center, start-1, -1):
        runningSum += lst[l]
        leftSum = max(leftSum, runningSum)
      runningSum = 0
      for r in range(center+1, end+1, 1):
        runningSum += lst[r]
        rightSum = max(rightSum, runningSum)
      centerSum = leftSum + rightSum
      return max(msa(lst, start, center), msa(lst, center+1, end), centerSum)
    return msa(nums, 0, len(nums)-1);

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
  for lst, answer in testCases[:]:
    print(f'{lst} => {answer}  -->  ', end='')
    res = soln.maxSubArray_DnC(lst)
    print(res, end='')
    if res != answer:
      success = False
      print(' \033[91mFAIL\033[0m')
    else:
      print('')
  if success:
    print('\033[92mTESTS PASSED!\033[0m')


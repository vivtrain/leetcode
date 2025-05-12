#!/bin/python3

from sys import path
path.append("../../Utility/python/")

from typing import List

class Solution(object):
  def threeSum(self, nums: List[int]) -> List[List[int]]:
    if (len(nums) < 3):
      return []
    nums.sort()
    result: List[List[int]] = []
    for i in range(len(nums)):
      if i > 0 and nums[i] == nums[i-1]:
        continue
      l, r = i+1, len(nums)-1
      while l < r:
        if l > i+1 and nums[l-1] == nums[l]:
          l += 1
          continue
        threeSum = nums[i] + nums[l] + nums[r]
        if threeSum < 0:
          l += 1
        elif threeSum > 0:
          r -= 1
        else:
          result.append([nums[i], nums[l], nums[r]])
          l += 1
    return result

if __name__ == '__main__':
  soln = Solution()
  testCases = [
    [  ],
    [ 0, 0, 0 ],
    [ -1, 0, 1 ],
    [ 0, 0, 0, 0 ],
    [ -1, 0, 1, 0 ],
    [ 0, 0, 0, 0, 0 ],
    [ -1, 0, 1, 2, -1, -4 ],
    [ 0, -1, 1, -2, 2, 3, -4 ],
  ]

  for test in testCases:
    print(test, '->', soln.threeSum(test))


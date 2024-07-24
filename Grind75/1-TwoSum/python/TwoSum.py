#!/bin/python3

from __future__ import annotations

class Solution(object):
  def twoSum(self, nums: list[int], target: int) -> list[int]:
    numMap = {}
    for i in range(len(nums)):
      complement = target - nums[i]
      if complement in numMap:
        return [i,numMap[complement]]
      else:
        numMap[nums[i]] = i
    return []

if __name__ == '__main__':
  soln = Solution()
  testCases = []
  testCases.append(([], 0, {}))
  testCases.append(([1], 0, {}))
  testCases.append(([0,1], 1, {0,1}))
  testCases.append(([0,1,3,5,8], 3, {0,2}))
  testCases.append(([0,1,3,5,8], 6, {1,3}))
  testCases.append(([0,1,3,5,8], 9, {1,4}))
  
  for test in testCases:
    print(test[0], ',', test[1], '=>', test[2], '==? ', end='')
    result = soln.twoSum(test[0], test[1])
    print(set(result))
    assert set(test[2]) == set(result)
  print('TESTS PASSED!')


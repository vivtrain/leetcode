#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from List import *

class Solution:
  def maxProfit(self, prices: list[int]) -> int:
    if len(prices) < 2:
      return 0
    buy = 0
    sell = 1
    maxProfit = 0
    while buy < sell and sell < len(prices):
      profit = prices[sell] - prices[buy]
      if profit < 0:
        buy = sell
      if profit > maxProfit:
        maxProfit = profit
      sell = sell + 1
    return maxProfit


if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ([], 0),
      ([1], 0),
      ([1,2], 1),
      ([2,1], 0),
      ([1,2,3], 2),
      ([1,3,2], 2),
      ([3,2,1], 0),
      ([7,1,5,3,6,4], 5),
      ]

  for test in testCases:
    print(test[0], '=>?', test[1])
    assert soln.maxProfit(test[0]) == test[1]
  print('TESTS PASSED!')


#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import Dict, List

class Solution(object):
  def coinChange(self, coins: List[int], amount: int) -> int:
    lookupTable: List[int] = []
    lookupTable.append(0)
    for amt in range(1,amount+1):
      options: List[int] = []
      for coin in coins:
        leftover = amt - coin
        if leftover >= 0 and lookupTable[leftover] != -1:
          options.append(lookupTable[leftover])
      if len(options) > 0:
        lookupTable.append(min(options) + 1)
      else:
        lookupTable.append(-1)
    return lookupTable[amount]

if __name__ == '__main__':
  soln = Solution()
  coins = [3,5,7]
  print(coins)
  for amount in range(25):
    print("amount: ",amount,", coins needed: ",soln.coinChange(coins, amount),sep="")


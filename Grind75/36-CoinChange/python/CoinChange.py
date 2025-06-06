#!/bin/python3

from __future__ import annotations
from collections import defaultdict
import sys
sys.path.append('../../Utility/python')
from typing import DefaultDict, Dict, List, Optional

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

  def coinChange2(self, coins: List[int], amount: int) -> Optional[List[int]]:
    cache: List[Optional[List[int]]] = [None] * (amount + 1)
    cache[0] = []
    for amt in range(1, amount+1):
      for denom in coins:
        leftover = cache[amt - denom] if amt - denom >= 0 else None
        cached = cache[amt]
        if leftover is not None \
            and (cached is None or len(leftover) + 1 < len(cached)):
          toInsert = leftover.copy()
          toInsert.append(denom)
          cache[amt] = toInsert
    return cache[amount]

  def coinChange3(self, coins: List[int], amount: int) -> Optional[DefaultDict[int,int]]:
    cache: List[Optional[DefaultDict[int,int]]] = [None] * (amount + 1)
    cache[0] = defaultdict(lambda: 0)
    def countCoins(coinMap: DefaultDict[int,int]):
      return sum(coinMap.values())
    for amt in range(1, amount+1):
      for denom in coins:
        leftover = cache[amt - denom] if amt - denom >= 0 else None
        cached = cache[amt]
        if leftover is not None \
            and (cached is None or countCoins(leftover) + 1 < countCoins(cached)):
          toInsert = leftover.copy()
          toInsert[denom] += 1
          cache[amt] = toInsert
    return cache[amount]

if __name__ == '__main__':
  soln = Solution()
  coins = [3,5,7]
  print(coins)
  for amount in range(25):
    result =  soln.coinChange3(coins, amount)
    result = dict(result) if result is not None else None
    print("amount: ",amount,", coins needed: ",result,sep="")


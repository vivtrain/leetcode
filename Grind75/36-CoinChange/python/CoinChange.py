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

  def coinChange3(self, coins: List[int], amount: int) -> Optional[Dict[int,int]]:
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
    result = cache[amount]
    return dict(result) if result is not None else None
  
  def coinChange4(self, coins: Dict[int,int], amount: int) -> Optional[Dict[int,int]]:
    cache: List[Optional[DefaultDict[int,int]]] = [None] * (amount + 1)
    cache[0] = defaultdict(lambda: 0)
    def countCoins(coinMap: DefaultDict[int,int]):
      return sum(coinMap.values())
    for amt in range(1, amount+1):
      for denom in coins:
        leftover = cache[amt - denom] if amt - denom >= 0 else None
        cached = cache[amt]
        if leftover is not None \
            and (cached is None or countCoins(leftover) + 1 < countCoins(cached)) \
            and (leftover[denom] < coins[denom]):
          toInsert = leftover.copy()
          toInsert[denom] += 1
          cache[amt] = toInsert
    result = cache[amount]
    if result is not None:
      for denom in coins:
        result[denom] = result[denom]
      return result
    else:
      return None

if __name__ == '__main__':
  soln = Solution()
  coins = { 1:10, 4:1, 5:5 }
  print(coins)
  def maxValue(coinDict: Dict[int,int]):
    sum = 0
    for coin, value in coinDict.items():
      sum += coin * value
    return sum
  for amount in range(maxValue(coins) + 2):
    result =  soln.coinChange4(coins, amount)
    result = dict(result) if result is not None else None
    print("amount: ",amount,", coins needed: ",result,sep="")


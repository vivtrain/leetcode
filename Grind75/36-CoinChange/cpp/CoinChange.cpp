#include "CoinChange.h"
#include <iostream>
#include <optional>
#include <unordered_map>
#include <vector>

using namespace std;

int CoinChange::coinChange(vector<int>& coins, int amount) {
  vector<int> lookup(amount+1);
  lookup[0] = 0;
  for (int amt = 1; amt <= amount; amt++) {
    int bestOption = -1;
    for (int coinValue : coins) {
      int leftover = amt - coinValue;
      if (leftover >= 0 && lookup[leftover] != -1) {
        int option = lookup[leftover];
        if (option < bestOption || bestOption == -1)
          bestOption = option;
      }
    }
    lookup[amt] = (bestOption == -1) ? -1 : bestOption + 1;
  }
  return lookup[amount];
}

optional<unordered_map<int,int>> CoinChange::coinChange2(
    const unordered_map<int,int> &coins,
    int amount) {
  vector<optional<unordered_map<int,int>>> cache(amount + 1);
  cache[0] = unordered_map<int,int>();
  for (int amt = 1; amt <= amount; amt++) {
    for (pair coin : coins) {
      int denom = coin.first;
      int leftover = amt - denom;
      if (leftover >= 0 && countCoins(cache[leftover]) < countCoins(cache[amt]) - 1
          && cache[leftover].has_value() && (*cache[leftover])[denom] < coins.at(denom)) {
        cache[amt] = cache[leftover];
        (*cache[amt])[denom]++;
      }
    }
  }
  return cache[amount];
}


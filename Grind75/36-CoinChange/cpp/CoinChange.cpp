#include "CoinChange.h"
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

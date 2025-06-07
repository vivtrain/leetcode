#include "CoinChange.h"
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <prettyPrint.h>

using namespace std;

void printMap(const unordered_map<int,int> &map) {
  cout << "{ ";
  for (pair p : map)
    cout << p.first << ":" << p.second << ", ";
  cout << "}" << endl;
}

int main() {
  CoinChange soln;
  unordered_map<int, int> coins { {3,3}, {5,1} };
  printMap(coins);
  for (int i = 0; i <= 15; i++) {
    optional<unordered_map<int,int>> result = soln.coinChange2(coins, i);
    if (result.has_value()) {
      cout << "to make " << i << " cents, you need " << soln.countCoins(result) << " coins: ";
      printMap(*result);
    }
    else
      cout << "to make " << i << " cents, you can't" << endl;
  }
}


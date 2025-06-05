#include "CoinChange.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  CoinChange soln;
  vector<int> coins { 3, 5 };
  prettyPrint(coins);
  for (int i = 0; i <= 15; i++) {
    cout << "to make " << i << " cents, you need "
         << soln.coinChange(coins, i) << " coins" << endl;
  }
}


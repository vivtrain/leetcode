#ifndef COIN_CHANGE
#define COIN_CHANGE

#include <climits>
#include <unordered_map>
#include <vector>
#include <optional>

class CoinChange {
  public:
    int coinChange(std::vector<int>& coins, int amount);
    std::optional<std::unordered_map<int,int>>
      coinChange2(const std::unordered_map<int,int> &coins, int amount);
    int countCoins(const std::optional<std::unordered_map<int,int>> &coins) {
      if (!coins.has_value())
        return INT_MAX;
      int sum = 0;
      for (std::pair coin : *coins)
        sum += coin.second;
      return sum;
    }
  private:
};

#endif


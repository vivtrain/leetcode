#include "BestTimeToBuyAndSellStock.h"

int BestTimeToBuyAndSellStock::maxProfit(std::vector<int>& prices) {
  if (prices.size() < 2)
    return 0;

  std::vector<int>::const_iterator buy, sell;
  int maxProfit = 0;
  for (buy = prices.begin(), sell = buy+1; sell != prices.end();) {
    int profit = *sell - *buy;
    if (profit < 0)
      buy++;
    else {
      if (profit > maxProfit)
        maxProfit = profit;
      sell++;
    }
  }
  return maxProfit;
}


#include "BestTimeToBuyAndSellStock.h"
#include "../../Utility/prettyPrint.h"
#include <cassert>
#include <tuple>

int main() {
  BestTimeToBuyAndSellStock b;
  std::vector<std::pair<std::vector<int>, int>> testCases;
  testCases.push_back(std::make_pair(std::vector<int>({}),                 0));
  testCases.push_back(std::make_pair(std::vector<int>({1}),                0));
  testCases.push_back(std::make_pair(std::vector<int>({1,2}),              1));
  testCases.push_back(std::make_pair(std::vector<int>({2,1}),              0));
  testCases.push_back(std::make_pair(std::vector<int>({1,2,3}),            2));
  testCases.push_back(std::make_pair(std::vector<int>({1,3,2}),            2));
  testCases.push_back(std::make_pair(std::vector<int>({7,1,5,3,6,4}),      5));
  testCases.push_back(std::make_pair(std::vector<int>({7,6,4,3,1}),        0));
  for (auto test : testCases) {
    int result = b.maxProfit(test.first);
    std::cout << prettyString(test.first) << " --> "
        << test.second << " ==? " << result << std::endl;
    assert(test.second == result);
  }
  std::cout << "Tests Passed!" << std::endl;
}


#include "InsertInterval.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <string>
#include <prettyPrint.h>

std::string strIntervals(const std::vector<std::vector<int>> &intervals) {
  std::string output = "[ ";
  if (intervals.size() > 0) {
    for (size_t i = 0; i < intervals.size()-1; i++) {
      output += '[' + std::to_string(intervals[i][0]) + ','
        + std::to_string(intervals[i][1]) + "],";
    }
    output += '[' + std::to_string(intervals[intervals.size()-1][0]) + ','
      + std::to_string(intervals[intervals.size()-1][1]) + "] ]";
  } else
    output += "]";
  return output;
}

int main() {
  using std::vector;
  using std::tuple;
  using std::get;
  InsertInterval soln;

  vector<tuple<vector<vector<int>>, vector<int>, vector<vector<int>>>> testCases
  {
    { {}, {0,1}, {{0,1}} },
    { {{0,1}}, {2,3}, {{0,1}, {2,3}} },
    { {{0,1}}, {0,1}, {{0,1}} },
    { {{0,1}}, {1,2}, {{0,2}} },
    { {{1,2}}, {0,1}, {{0,2}} },
    { {{1,2}}, {0,3}, {{0,3}} },
    { {{0,1},{2,3},{4,5},{6,7}}, {3,4}, {{0,1},{2,5},{6,7}} },
    { {{0,1},{2,3},{6,7}}, {4,5}, {{0,1},{2,3},{4,5},{6,7}} },
  };

  bool success = true;
  for (auto test : testCases) {
    std::cout << strIntervals(get<0>(test)) << ", add "
      << prettyString(get<1>(test)) << std::endl;
    std::cout << "\t" << strIntervals(get<2>(test)) << std::endl;
    vector<vector<int>> result = soln.insert(get<0>(test), get<1>(test));
    std::cout << "->\t" << strIntervals(result) << std::endl;
    if (result != get<2>(test)) {
      success = false;
      std::cout << "\t\e[31mFAIL\e[0m" << std::endl;
    }
  }
  if (success) {
      std::cout << "\t\e[32mTESTS PASSED!\e[0m" << std::endl;
  }
}


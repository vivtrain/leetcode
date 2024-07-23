#include "BinarySearch.h"
#include <iostream>
#include "../../Utility/prettyPrint.h"
#include <cassert>
#include <vector>
#include <tuple>

int main() {
  BinarySearch soln;
  std::vector<std::tuple<std::vector<int>, int, int>> testCases;
  testCases.push_back(std::make_tuple(std::vector<int>{}, 0, -1));
  testCases.push_back(std::make_tuple(std::vector<int>{0}, 0, 0));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2}, 0, 0));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2}, 2, 1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2}, 1, -1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4}, 0, 0));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4}, 2, 1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4}, 4, 2));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4}, 1, -1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  0,  0));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  2,  1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  4,  2));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  6,  3));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  8,  4));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8}, -1, -1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  9, -1));
  testCases.push_back(std::make_tuple(std::vector<int>{0,2,4,6,8},  1, -1));
  
  for (auto test : testCases) {
    std::cout << prettyString(std::get<0>(test)) <<", "<< std::get<1>(test)
        <<" => "<< std::get<2>(test) <<" ==? "<< std::flush;
    int result = soln.search_it(std::get<0>(test), std::get<1>(test));
    std::cout << result << std::endl;
    assert(result == std::get<2>(test));
  }
  std::cout << "TESTS PASSED!" << std::endl;
}


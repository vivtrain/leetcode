#include "ValidParentheses.h"
#include <string>
#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>

int main() {
  ValidParentheses vp;
  std::vector<std::pair<std::string, bool>> testCases;
  testCases.push_back(std::make_pair("",       true));
  testCases.push_back(std::make_pair("(",      false));
  testCases.push_back(std::make_pair("[",      false));
  testCases.push_back(std::make_pair("[",      false));
  testCases.push_back(std::make_pair(")",      false));
  testCases.push_back(std::make_pair("]",      false));
  testCases.push_back(std::make_pair("}",      false));
  testCases.push_back(std::make_pair("()",     true));
  testCases.push_back(std::make_pair("[]",     true));
  testCases.push_back(std::make_pair("{}",     true));
  testCases.push_back(std::make_pair("()[]{}", true));
  testCases.push_back(std::make_pair("([{}])", true));
  testCases.push_back(std::make_pair("([]{})", true));
  testCases.push_back(std::make_pair("([{]})", false));
  for (std::pair<std::string, bool> test : testCases) {
    std::cerr << test.first << " ==> " << std::boolalpha << test.second
        << std::endl;
    assert(vp.isValid(test.first) == test.second);
  }
  std::cerr << "Tests Passed!" << std::endl;
}


#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

template<class VecType>
void prettyPrint(const std::vector<VecType>& vec) {
  std::cout << "[ ";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << ' ';
  }
  std::cout << ']' << std::endl;
}

template<class VecType>
std::string prettyString(const std::vector<VecType>& vec) {
  std::stringstream output;
  output << "[ ";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    output << *it << ' ';
  }
  output << ']';
  return output.str();
}

#endif


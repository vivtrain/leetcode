#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <vector>
#include <iostream>

template<class VecType>
void prettyPrint(const std::vector<VecType>& vec) {
  std::cout << "[ ";
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << ' ';
  }
  std::cout << ']' << std::endl;
}

#endif


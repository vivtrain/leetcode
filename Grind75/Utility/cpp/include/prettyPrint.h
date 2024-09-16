#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

template<class VecType>
void prettyPrint(const std::vector<VecType>& vec) {
  std::cout << '[';
  for (auto it = vec.begin(); it != vec.end()-1; it++)
    std::cout << *it << ", ";
  std::cout << *(vec.end()-1) << ']' << std::endl;
}

template<class VecType>
std::string prettyString(const std::vector<VecType>& vec) {
  std::stringstream output;
  output << '[';
  for (auto it = vec.begin(); it != vec.end()-1; it++)
    output << *it << ", ";
  output << *(vec.end()-1) << ']';
  return output.str();
}

template<class VecType>
void prettyPrint2D(const std::vector<std::vector<VecType>>& vec) {
  std::cout << "[";
  if (vec.size() > 0)
    std::cout << prettyString(*vec.begin());
  if (vec.size() > 1)
    std::cout << std::endl;
  if (vec.size() > 2)
    for (auto it = vec.begin()+1; it != vec.end()-1; it++)
      std::cout << " " << prettyString(*it) << '\n';
  if (vec.size() > 1)
    std::cout << " " << prettyString(*(vec.end()-1));
  std::cout << "]" << std::endl;
}

#endif


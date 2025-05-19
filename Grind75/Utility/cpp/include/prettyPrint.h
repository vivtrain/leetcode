#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "colors.h"

template<typename T>
void prettyPrint(const std::vector<T>& vec) {
  std::cout << '[';
  if (vec.size() > 0) {
    for (auto it = vec.begin(); it != vec.end()-1; it++)
      std::cout << *it << ", ";
    std::cout << *(vec.end()-1);
  }
  std::cout << ']' << std::endl;
}

template<typename T>
std::string prettyString(const std::vector<T>& vec) {
  std::stringstream output;
  output << '[';
  if (vec.size() > 0) {
    for (auto it = vec.begin(); it != vec.end()-1; it++)
      output << *it << ", ";
    output << *(vec.end()-1);
  }
  output << ']';
  return output.str();
}

template<class T>
void prettyPrint2D(const std::vector<std::vector<T>>& vec) {
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

template<typename T>
std::ostream& colorOut(const char *color) {
  return std::cout << color;
}

template<typename T>
std::ostream& colorOut(const char *color, const T &input) {
  return std::cout << color << input << colors::NO_COLOR;
}

#endif


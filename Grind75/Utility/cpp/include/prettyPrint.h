#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "colors.h"

template<typename T>
void prettyPrint(const std::vector<T>& vec, std::string delim=", ") {
  std::cout << '[';
  if (vec.size() > 0) {
    for (auto it = vec.begin(); it != vec.end()-1; it++)
      std::cout << *it << delim;
    std::cout << *(vec.end()-1);
  }
  std::cout << ']' << std::endl;
}

template<typename T>
std::string prettyString(const std::vector<T>& vec, std::string delim=", ") {
  std::stringstream output;
  output << '[';
  if (vec.size() > 0) {
    for (auto it = vec.begin(); it != vec.end()-1; it++)
      output << *it << delim;
    output << *(vec.end()-1);
  }
  output << ']';
  return output.str();
}

template<class T>
void prettyPrint2D(const std::vector<std::vector<T>>& vec, std::string outerDelim="\n ", std::string innerDelim=", ") {
  std::cout << "[";
  if (vec.size() > 0)
    std::cout << prettyString(*vec.begin(), innerDelim);
  if (vec.size() > 1)
    std::cout << outerDelim;
  if (vec.size() > 2)
    for (auto it = vec.begin()+1; it != vec.end()-1; it++)
      std::cout << prettyString(*it, innerDelim) << outerDelim;
  if (vec.size() > 1)
    std::cout << prettyString(*(vec.end()-1), innerDelim);
  std::cout << "]" << std::endl;
}

template<class T>
std::string prettyString2D(const std::vector<std::vector<T>>& vec, std::string outerDelim="\n", std::string innerDelim=", ") {
  std::stringstream output;
  output << "[";
  if (vec.size() > 0)
    output << prettyString(*vec.begin(), innerDelim);
  if (vec.size() > 1)
    output << outerDelim;
  if (vec.size() > 2)
    for (auto it = vec.begin()+1; it != vec.end()-1; it++)
      output << prettyString(*it, innerDelim) << outerDelim;
  if (vec.size() > 1)
    output << prettyString(*(vec.end()-1), innerDelim);
  output << "]";
  return output.str();
}

template<typename T>
std::ostream& colorOut(const char *color) {
  return std::cout << color;
}

template<typename T>
std::ostream& _colorOut(const T& input) {
  return std::cout << input;
}
template<typename First, typename... Rest>
std::ostream& _colorOut(const First &first, const Rest&... rest) {
  std::cout << first;
  return _colorOut(rest...);
}
template<typename... T>
std::ostream& colorOut(const char *color, const T&... input) {
  std::cout << color;
  _colorOut(input...);
  return std::cout << colors::NO_COLOR;
}


#endif


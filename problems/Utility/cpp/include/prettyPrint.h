#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

namespace colors {
  const std::string RESET =   "\033[0m";
  const std::string BLACK =   "\033[30m";
  const std::string RED =     "\033[31m";
  const std::string GREEN =   "\033[32m";
  const std::string YELLOW =  "\033[33m";
  const std::string BLUE =    "\033[34m";
  const std::string MAGENTA = "\033[35m";
  const std::string CYAN =    "\033[36m";
  const std::string WHITE =   "\033[37m";
  const std::string BOLD_BLACK =   "\033[1m\033[30m";
  const std::string BOLD_RED =     "\033[1m\033[31m";
  const std::string BOLD_GREEN =   "\033[1m\033[32m";
  const std::string BOLD_YELLOW =  "\033[1m\033[33m";
  const std::string BOLD_BLUE =    "\033[1m\033[34m";
  const std::string BOLD_MAGENTA = "\033[1m\033[35m";
  const std::string BOLD_CYAN =    "\033[1m\033[36m";
  const std::string BOLD_WHITE =   "\033[1m\033[37m";
}

template<class T>
void prettyPrint(const std::vector<T>& vec) {
  std::cout << '[';
  if (vec.size() > 0) {
    for (auto it = vec.begin(); it != vec.end()-1; it++)
      std::cout << *it << ", ";
    std::cout << *(vec.end()-1);
  }
  std::cout << ']' << std::endl;
}

template<class T>
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

template<class T>
std::ostream& colorOut(const T &input, const std::string& color) {
  return std::cout << color << input << colors::RESET;
}

#endif


#ifndef PRETTY_PRINT
#define PRETTY_PRINT

#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "colors.h"

// PRETTY PRINT ╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍
template<typename T>
void prettyPrint(const std::vector<T>& vec, std::string delim=", ") {
  std::cout << '[';
  if (vec.size() > 0) {
    auto it = vec.begin();
    for (auto itAhead = ++vec.begin(); itAhead != vec.end(); it++, itAhead++)
      std::cout << *it << delim;
    std::cout << *it;
  }
  std::cout << ']' << std::endl;
}
template<typename T>
void prettyPrint(const std::set<T> &set, std::string delim=", ") {
  std::cout << '{';
  if (set.size() > 0) {
    auto it = set.begin();
    for (auto itAhead = ++set.begin(); itAhead != set.end(); it++, itAhead++)
      std::cout << *it << delim;
    std::cout << *it;
  }
  std::cout << '}' << std::endl;
}
template<typename T>
void prettyPrint(const std::unordered_set<T> &uset, std::string delim=", ") {
  std::cout << '{';
  if (uset.size() > 0) {
    auto it = uset.begin();
    for (auto itAhead = ++uset.begin(); itAhead != uset.end(); it++, itAhead++)
      std::cout << *it << delim;
    std::cout << *it;
  }
  std::cout << '}' << std::endl;
}
template<typename T1, typename T2>
void prettyPrint(
    const std::map<T1, T2> &map,
    std::string delim=", ",
    std::string betw=": ") {
  std::cout << '{';
  if (map.size() > 0) {
    auto it = map.begin();
    for (auto itAhead = ++map.begin(); itAhead != map.end(); it++, itAhead++)
      std::cout << it->first << betw << it->second << delim;
    std::cout << it->first << betw << it->second;
  }
  std::cout << '}' << std::endl;
}
template<typename T1, typename T2>
void prettyPrint(
    const std::unordered_map<T1, T2> &umap,
    std::string delim=", ",
    std::string betw=": ") {
  std::cout << '{';
  if (umap.size() > 0) {
    auto it = umap.begin();
    for (auto itAhead = ++umap.begin(); itAhead != umap.end(); it++, itAhead++)
      std::cout << it->first << betw << it->second << delim;
    std::cout << it->first << betw << it->second;
  }
  std::cout << '}' << std::endl;
}

// PRETTY STRING ╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍
template<typename T>
std::string prettyString(const std::vector<T>& vec, std::string delim=", ") {
  std::stringstream output;
  output << '[';
  if (vec.size() > 0) {
    auto it = vec.begin();
    for (auto itAhead = ++vec.begin(); itAhead != vec.end(); it++, itAhead++)
      output << *it << delim;
    output << *it;
  }
  output << ']';
  return output.str();
}
template<typename T>
std::string prettyString(const std::set<T>& set, std::string delim=", ") {
  std::stringstream output;
  output << '{';
  if (set.size() > 0) {
    auto it = set.begin();
    for (auto itAhead = ++set.begin(); itAhead != set.end(); it++, itAhead++)
      output << *it << delim;
    output << *it;
  }
  output << '}';
  return output.str();
}
template<typename T>
std::string prettyString(
    const std::unordered_set<T>& uset,
    std::string delim=", ") {
  std::stringstream output;
  output << '{';
  if (uset.size() > 0) {
    auto it = uset.begin();
    for (auto itAhead = ++uset.begin(); itAhead != uset.end(); it++, itAhead++)
      output << *it << delim;
    output << *it;
  }
  output << '}';
  return output.str();
}
template<typename T1, typename T2>
std::string prettyString(
    const std::map<T1, T2>& map,
    std::string delim=", ",
    std::string betw=": ") {
  std::stringstream output;
  output << '{';
  if (map.size() > 0) {
    auto it = map.begin();
    for (auto itAhead = ++map.begin(); itAhead != map.end(); it++, itAhead++)
      output << it->first << betw << it->second << delim;
    output << it->first << betw << it->second;
  }
  output << '}';
  return output.str();
}
template<typename T1, typename T2>
std::string prettyString(
    const std::unordered_map<T1, T2>& umap,
    std::string delim=", ",
    std::string betw=": ") {
  std::stringstream output;
  output << '{';
  if (umap.size() > 0) {
    auto it = umap.begin();
    for (auto itAhead = ++umap.begin(); itAhead != umap.end(); it++, itAhead++)
      output << it->first << betw << it->second << delim;
    output << it->first << betw << it->second;
  }
  output << '}';
  return output.str();
}

// PRETTY PRINT 2D ╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍
template<typename T>
void prettyPrint2D(
    const std::vector<std::vector<T>>& vec,
    std::string outerDelim=",\n ",
    std::string innerDelim=", ") {
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

// PRETTY STRING 2D ╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍╍
template<typename T>
std::string prettyString2D(
    const std::vector<std::vector<T>>& vec,
    std::string outerDelim=",\n ",
    std::string innerDelim=", ") {
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


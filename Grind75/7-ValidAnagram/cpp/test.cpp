#include "ValidAnagram.h"
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <tuple>

int main() {
  ValidAnagram soln;
  std::vector<std::tuple<std::string, std::string, bool>> testCases;
  testCases.push_back(std::make_tuple("", "", true));
  testCases.push_back(std::make_tuple("", "a", false));
  testCases.push_back(std::make_tuple("a", "a", true));
  testCases.push_back(std::make_tuple("a", "b", false));
  testCases.push_back(std::make_tuple("anagram", "anagram", true));
  testCases.push_back(std::make_tuple("anagram", "nagaram", true));
  testCases.push_back(std::make_tuple("anagram", "anagran", false));

  for (auto test : testCases) {
    std::cout <<'"'<< std::get<0>(test) << "\" \""
                   << std::get<1>(test) << "\" => " << std::boolalpha
                   << std::get<2>(test) << " ==? " << std::flush;
    bool result = soln.isAnagram(std::get<0>(test), std::get<1>(test));
    std::cout << result << std::endl;;
    assert(result == std::get<2>(test));
  }
  std::cout << "TESTS PASSED!" << std::endl;
}


#include "ValidPalindrome.h"
#include <iostream>
#include <vector>
#include <tuple>

int main() {
  ValidPalindrome v;
  std::vector<std::pair<std::string, bool>> testCases;
  testCases.push_back(std::make_pair("", true));
  testCases.push_back(std::make_pair("a", true));
  testCases.push_back(std::make_pair("ab", false));
  testCases.push_back(std::make_pair("aba", true));
  testCases.push_back(std::make_pair("abA", true));
  testCases.push_back(std::make_pair("ab a", true));
  testCases.push_back(std::make_pair("...", true));
  testCases.push_back(std::make_pair("A man, a plan, a canal: Panama", true));

  for (auto test : testCases) {
    std::cout << std::boolalpha <<'"'<<test.first<<'"'<< " => " << test.second
        << std::flush;
    bool result = v.isPalindrome_it(test.first);
    std::cout << std::boolalpha << " ==? " << result << std::endl;
  }

  std::cout << "TESTS PASSED!" << std::endl;
}


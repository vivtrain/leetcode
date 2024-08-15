#include "LongestPalindrome.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  LongestPalindrome soln;
  vector<pair<string, int>> testCases {
      {"", 0},
      {"a", 1},
      {"ab", 1},
      {"abc", 1},
      {"abcd", 1},
      {"aa", 2},
      {"aba", 3},
      {"abba", 4},
      {"abcba", 5},
      {"abccccba", 8},
      {"abbcccddddcccbba", 16},
      {"abbcccddzddcccbba", 17}
  };

  for (pair<string, int> test : testCases) {
    int result = soln.longestPalindrome(test.first);
    cout << test.first <<", "<< test.second <<" -> "<< result << endl;
    assert(result == test.second);
  }
  cout << "TESTS PASSED!" << endl;
}


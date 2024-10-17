#include "LongestSubstringWithoutRepeat.h"
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

int main() {
  LongestSubstringWithoutRepeat soln;
  vector<pair<string, int>> testCases {
    {"", 0},
    {"a", 1},
    {"aa", 1},
    {"aaa", 1},
    {"ab", 2},
    {"abb", 2},
    {"aab", 2},
    {"aba", 2},
    {"abab", 2},
    {"abababab", 2},
    {"abc", 3},
    {"abcabcd", 4},
    {"abac", 3},
  };

  bool success = true;
  for (auto test : testCases) {
    cout << "\""+test.first+"\"" << " --> " << test.second;
    int result = soln.lengthOfLongestSubstring(test.first);
    if (result != test.second) {
      cout << " \e[31mFAIL\e[0m" << " --> " << result;
      success = false;
    }
    cout << endl;
  }
  if (success)
    cout << "\e[32mTESTS PASSED!\e[0m" << endl;
}


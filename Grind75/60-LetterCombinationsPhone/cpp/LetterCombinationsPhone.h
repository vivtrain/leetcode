#ifndef LETTER_COMBINATIONS_PHONE
#define LETTER_COMBINATIONS_PHONE

#include <vector>
#include <string>

class Solution {
  public:
    std::vector<std::string> letterCombinations(std::string digits);
  private:
    const std::vector<std::string> num2let {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
};

#endif


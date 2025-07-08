#include "LetterCombinationsPhone.h"
#include <vector>
#include <string>

using namespace std;

vector<string> Solution::letterCombinations(string digits) {
  if (digits.empty())
    return {};
  vector<string> combinations {""};
  for (const char digit : digits) {
    const string &letters = num2let[digit - '0'];
    vector<string> newCombs;
    for (string &comb : combinations)
      for (const char letter : letters)
        newCombs.push_back(comb + letter);
    combinations = std::move(newCombs);
  }
  return combinations;
}


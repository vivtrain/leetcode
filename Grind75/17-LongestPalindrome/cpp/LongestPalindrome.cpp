#include "LongestPalindrome.h"
#include <string>
#include <bitset>

int LongestPalindrome::longestPalindrome(std::string s) {
  std::bitset<26*2> odds;
  for (char c : s)
    odds[c-'A'].flip();
  return s.length() - odds.count() + odds.any();
}


#include "LongestPalindromicSubstring.h"
#include <string>

using namespace std;

string Solution::longestPalindrome(string s) {
  if (s.size() < 2)
    return s;
  int bestStart = 0, bestLength = 1;
  int N = s.size();
  for (int center = 1; center < N; center++) {
    int l, r, length;
    const int c = center;

    // check odd palindromes
    for (l = r = c; l >= 0 && r < N && s[l] == s[r]; l--,r++) {
      length = r - l + 1;
      if (length > bestLength) {
        bestLength = length;
        bestStart = l;
      }
    }

    // check even palindromes
    for (l = c-1, r = c; l >= 0 && r < N && s[l] == s[r]; l--,r++) {
      length = r - l + 1;
      if (length > bestLength) {
        bestLength = length;
        bestStart = l;
      }
    }
  }
  return s.substr(bestStart, bestLength);
}


#include "LongestPalindromicSubstring.h"
#include "colors.h"
#include <iomanip>
#include <string>
#include <prettyPrint.h>
#include <utility>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<string, string>> testCases {
    { "", "" },
    { "a", "a" },
    { "ab", "a" },
    { "aa", "aa" },
    { "aba", "aba" },
    { "aaba", "aba" },
    { "abaa", "aba" },
    { "aaa", "aaa" },
    { "abba", "abba" },
    { "aabba", "abba" },
    { "abbaa", "abba" },
    { "aaaa", "aaaa" },
    { "aaaaa", "aaaaa" },
    { "aaaaaa", "aaaaaa" },
  };

  for (const auto &[s, answer] : testCases) {
    colorOut(LIGHT_BLUE, quoted(s), " => ", quoted(answer)) << " --> ";
    string result = soln.longestPalindrome(s);
    colorOut(result == answer ? GREEN: RED, quoted(result)) << endl;
  }
}


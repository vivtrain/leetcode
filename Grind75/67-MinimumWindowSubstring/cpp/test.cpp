#include "MinimumWindowSubstring.h"
#include "colors.h"
#include <iomanip>
#include <prettyPrint.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<string, string, string>> testCases {
    { "A", "AA", "" },
    { "AA", "A", "A" },
    { "AB", "C", "" },
    { "ABCDAB", "ABC", "ABC" },
    { "ABDCAB", "ABC", "CAB" },
    { "AABADADAC", "AABC", "BADADAC" },
    { "ABCADBCADBDC", "ABC", "ABC" },
    { "ABCADBCADBDC", "ABCD", "BCAD" },
    { "ABCADBCADBDC", "AABCD", "ABCAD" },
    { "ABCADBCADBDC", "AABCDD", "ADBCAD" },
    { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabc", "abc", "abc" },
  };

  for (auto &[s, t, answer] : testCases) {
    colorOut(LIGHT_BLUE, quoted(s), ", ", quoted(t),
        " => ", quoted(answer)) << endl;
    string result = soln.minWindow(s, t);
    colorOut(result == answer ? GREEN : RED, quoted(result)) << endl;
  }
}


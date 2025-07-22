#include "BasicCalculator.h"
#include "colors.h"
#include <iomanip>
#include <iostream>
#include <prettyPrint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<string, int>> testCases {
    { "", 0 },
    { "1", 1 },
    { "(2)", 2 },
    { "1 + 2", 3 },
    { "1 - 2", -1 },
    { "2- 1 + 2", 3 },
    { "1 + 2 + (3 + 4)", 10 },
    { "1 + 2 - (3 + 4)", -4 },
    { "1 + -2 + (3 + 4)", 6 },
    { "1+-2 -(3 + 4)", -8 },
  };

  for (auto &[s, answer] : testCases) {
    colorOut(LIGHT_BLUE, quoted(s), " => ", answer);
    int result = soln.calculate(s);
    colorOut(result == answer ? GREEN : RED, " --> ", result) << endl;
  }
}


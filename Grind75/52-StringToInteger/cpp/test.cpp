#include "StringToInteger.h"
#include "colors.h"
#include <iomanip>
#include <utility>
#include <vector>
#include <string>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<string, int>> testCases {
    { "",      0 },
    { "a",     0 },
    { "0",     0 },
    { "1",     1 },
    { " 1",    1 },
    { "   1",  1 },
    { "   1a", 1 },
    { "   -123a",  -123 },
    { "   +123a",   123 },
    { "   +123.5a", 123 },
    { "2147483647",     2147483647 },
    { "2147483648",     2147483647 },
    { "214748364700",   2147483647 },
    { "-2147483648",   -2147483648 },
    { "-2147483649",   -2147483648 },
    { "-214748364800", -2147483648 },
    { "-3147483648",   -2147483648 },
    { "-9999999999",   -2147483648 },
    { "1000000000000000000000000000000000000000000000000000", 2147483647 },
    { "-1000000000000000000000000000000000000000000000000000", -2147483648 },
    { "0000000000000000000000000000000000000000000000000001", 1 },
  };

  for (auto &[str, answer] : testCases) {
    colorOut(LIGHT_BLUE, quoted(str), " => ", answer) << endl;
    int result = soln.myAtoi(str);
    colorOut(result == answer ? GREEN : RED, result) << endl;
  }
}


#include "EditDistance.h"
#include <prettyPrint.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<string, string, int>> testCases {
    { "coarse", "horse", 2 },
    { "horse", "ros", 3 },
    { "intention", "execution", 5 },
    { "a", "", 1 },
  };

  for (const auto &[w1, w2, ans] : testCases) {
    colorOut(LIGHT_BLUE, w1, " -> ", w2, " => ", ans) << endl;
    int result = soln.minDistance(w1, w2);
    colorOut(result == ans ? GREEN : RED, result) << endl;
  }
}


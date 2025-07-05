#include "UniquePaths.h"
#include <prettyPrint.h>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<int, int, int>> testCases {
    { 0, 0, 0 },
    { 0, 1, 0 },
    { 1, 0, 0 },
    { 1, 1, 1 },
    { 1, 2, 1 },
    { 2, 1, 1 },
    { 3, 2, 3 },
    { 2, 3, 3 },
    { 4, 5, 35 },
    { 6, 3, 21 },
  };

  for (auto [m, n, answer] : testCases) {
    vector<vector<char>> grid(m, vector<char>(n, 'x'));
    colorOut(LIGHT_BLUE, prettyString2D(grid)) << endl;
    colorOut(WHITE, "m: ", m, ",n: ", n, " => ", answer, "\n");
    int result = soln.uniquePaths(m, n);
    colorOut(result == answer ? GREEN : RED, result) << endl;
  }
}


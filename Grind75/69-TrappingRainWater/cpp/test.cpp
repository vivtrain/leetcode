#include "TrappingRainWater.h"
#include <prettyPrint.h>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<int>, int>> testCases {
    { {0}, 0 },
    { {1}, 0 },
    { {0,1}, 0 },
    { {1,0}, 0 },
    { {1,1}, 0 },
    { {0,1,0}, 0 },
    { {1,0,1}, 1 },
    { {1,0,2,1,2}, 2 },
    { {1,0,2,1,0}, 1 },
    { {1,0,2,0,3}, 3 },
    { {0,1,0,2,1,0,1,3,2,1,2,1}, 6 },
    { {4,2,0,2,5}, 8 },
    { {4,2,0,3,2,5}, 9 },
  };

  for (auto &[height, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(height), " => ", answer) << endl;
    int result = soln.trap(height);
    colorOut(result == answer ? GREEN : RED, "  --> ", result) << endl;
  }
}


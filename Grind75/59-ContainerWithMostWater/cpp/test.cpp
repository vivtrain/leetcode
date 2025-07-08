#include "ContainerWithMostWater.h"
#include "colors.h"
#include <prettyPrint.h>
#include <utility>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<int>, int>> testCases {
    { {}, 0 },
    { {1}, 0 },
    { {1,1}, 1 },
    { {1,2}, 1 },
    { {2,1}, 1 },
    { {2,2}, 2 },
    { {2,4,1,3,1,2,4,1}, 20 },
    { {1,1,6,6,1,1}, 6 },
    { {1,1,1,6,6,1,1,1}, 7 },
    { {1,8,6,2,5,4,8,3,7}, 49 },
  };

  for (auto &[heights, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(heights), " => ", answer) << flush;
    int result = soln.maxArea(heights);
    cout << " --> ";
    colorOut(result == answer ? GREEN : RED, result) << endl;
  }
}


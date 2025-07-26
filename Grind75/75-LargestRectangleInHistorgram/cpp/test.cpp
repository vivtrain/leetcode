#include "LargestRectangleInHistorgram.h"
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
    { {1}, 1 },
    { {1,2}, 2 },
    { {2,1}, 2 },
    { {2,1}, 2 },
    { {2,1,2}, 3 },
    { {2,1,4}, 4 },
    { {2,1,0,2}, 2 },
    { {2,1,4,3,1}, 6 },
    { {2,1,4,3,1,1,1}, 7 },
    { {2,1,2,2,2}, 6 },
    { {3,3,3,1,3,3}, 9 },
    { {3,1,5,6,3,4,2}, 12 },
    { {3,6,5,7,4,8,1,0}, 20 },
  };

  for (auto &[heights, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(heights), " => ", answer) << endl;
    vector<int> indices(heights.size());
    for (uint i = 0; i < heights.size(); i++) indices[i] = i;
    int result = soln.largestRectangleArea(heights);
    colorOut(result == answer ? GREEN : RED, "--> ", result) << endl;
  }
}


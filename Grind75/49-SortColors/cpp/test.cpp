#include "SortColors.h"
#include "colors.h"
#include <utility>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  vector<pair<vector<int>, vector<int>>> testCases {
    { {}, {} },
    { {0}, {0} },
    { {0,2}, {0,2} },
    { {1,2}, {1,2} },
    { {1,1}, {1,1} },
    { {1,0}, {0,1} },
    { {2,1}, {1,2} },
    { {0,1,2}, {0,1,2} },
    { {0,2,1}, {0,1,2} },
    { {1,0,2}, {0,1,2} },
    { {1,2,0}, {0,1,2} },
    { {2,0,1}, {0,1,2} },
    { {2,1,0}, {0,1,2} },
    { {2,0,2,1,1,0}, {0,0,1,1,2,2} },
  };
  Solution soln;
  for (auto &[nums, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(nums)) << endl;
    colorOut(WHITE, prettyString(answer)) << endl;
    soln.sortColors(nums);
    bool good = nums == answer;
    colorOut(good ? GREEN : RED, prettyString(nums)) << endl;
  }
}


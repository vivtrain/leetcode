#include "SearchRotatedArray.h"
#include "colors.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector<tuple<vector<int>, int, int>> testCases {
    { {}, 0, -1 },

    { {0}, 0, 0 },
    { {0}, 1, -1 },

    { {0,1}, 0, 0 },
    { {0,1}, 1, 1 },
    { {0,1}, 2, -1 },
    { {0,1}, -1, -1 },

    { {0,2}, 1, -1 },
    { {2,0}, 1, -1 },

    { {1,0}, 0, 1 },
    { {1,0}, 1, 0 },
    { {1,0}, 2, -1 },
    { {1,0}, -1, -1 },

    { {0,1,2}, 0, 0 },
    { {0,1,2}, 1, 1 },
    { {0,1,2}, 2, 2 },
    { {0,1,2}, 3, -1 },
    { {0,1,2}, -1, -1 },
    
    { {2,0,1}, 0, 1 },
    { {2,0,1}, 1, 2 },
    { {2,0,1}, 2, 0 },
    { {2,0,1}, 3, -1 },
    { {2,0,1}, -1, -1 },

    { {1,2,0}, 0, 2 },
    { {1,2,0}, 1, 0 },
    { {1,2,0}, 2, 1 },
    { {1,2,0}, 3, -1 },
    { {1,2,0}, -1, -1 },

    { {0,1,3}, 2, -1 },
    { {1,3,0}, 2, -1 },
    { {3,0,1}, 2, -1 },

    { {4,5,6,7,0,1,2}, 0, 4 },
    { {4,5,6,7,8,1,2,3}, 8, 4 },
    { {1,2,3,4,5,6}, 4, 3 },
  };

  for (auto &[ nums, toFind, answer ] : testCases) {
    colorOut(colors::LIGHT_BLUE, "Finding ") << toFind
      << " in " << prettyString(nums) << " => " << answer << " ";
    int result = soln.search3(nums, toFind);
    colorOut(colors::LIGHT_YELLOW, "Got: ");
    colorOut((result == answer) ? colors::GREEN : colors::RED, result) << endl;
  }
}


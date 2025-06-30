#include "PartitionEqualSubsetSum.h"
#include <utility>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<int>, bool>> testCases {
    { {1}, false },
    { {1,1}, true },
    { {1,2}, false },
    { {1,1,2}, true },
    { {6,7,1,12}, true },
    { {1,5,11,5}, true },
    { {1,2,3,5}, false },
    { {2,3,3}, false },
    { {2,2,2,3,3}, true },
    { {2,2,2,2,3,3}, true },
    { {10,10,10,10,10,10,10,10,10,10,9,7}, false },
    { {1,1,2,2,2,4,4,4,8}, true },
{ {4,4,4,4,4,4,4,4,8,8,8,8,8,8,8,8,12,12,12,12,12,12,12,12,16,16,16,16,16,16,16,16,20,20,20,20,20,20,20,20,24,24,24,24,24,24,24,24,28,28,28,28,28,28,28,28,32,32,32,32,32,32,32,32,36,36,36,36,36,36,36,36,40,40,40,40,40,40,40,40,44,44,44,44,44,44,44,44,48,48,48,48,48,48,48,48,52,52,52,52,52,52,52,52,56,56,56,56,56,56,56,56,60,60,60,60,60,60,60,60,64,64,64,64,64,64,64,64,68,68,68,68,68,68,68,68,72,72,72,72,72,72,72,72,76,76,76,76,76,76,76,76,80,80,80,80,80,80,80,80,84,84,84,84,84,84,84,84,88,88,88,88,88,88,88,88,92,92,92,92,92,92,92,92,96,96,96,96,96,96,96,96,97,99}, false }
  };
  for (auto &[nums, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(nums), " => ", boolalpha, answer) << endl;
    bool result = soln.canPartition(nums);
    cout << " --> ";
    colorOut(result == answer ? GREEN : RED, boolalpha, result) << endl;
  }
}


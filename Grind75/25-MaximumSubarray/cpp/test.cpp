#include "MaximumSubarray.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <prettyPrint.h>

int main() {
  using namespace std;
  MaximumSubarray soln;
  
  vector<pair<vector<int>, int>> testCases {
    {{1}, 1},
    {{1,2,3}, 6},
    {{1,2,-3}, 3},
    {{1,-2,3,-4,5}, 5},
    {{5,-1,-1,5}, 8},
    {{-2,1,-3,4,-1,2,1,-5,4}, 6},
    {{0,-3,1,1}, 2},
    {{1,1,-3,0}, 2},
    {{-1,-2,-2,-2,3,2,-2,0}, 5},
    {{1,2,-1,-2,2,1,-2,1}, 3},
  };
  for (auto test : testCases) {
    cout << prettyString(test.first) << ", " << test.second << " -> " << flush;
    int result = soln.maxSubArray(test.first);
    cout << result;
    if (result != test.second) {
      cout << " \e[91mFAIL\e[0m";
    }
    cout << endl;
  }
}


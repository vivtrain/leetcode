#include "MajorityElement.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <prettyPrint.h>

int main() {
  using namespace std;
  MajorityElement soln;

  vector<pair<vector<int>, int>> testCases {
    {{1}, 1},
    {{1,1,2}, 1},
    {{1,2,2}, 2},
    {{2,2,1,1,1,2,2}, 2},
    {{2,2,1,1,1,2,2}, 2},
  };

  for (auto test : testCases) {
    cout << prettyString(test.first) <<", "<< test.second << " -> " << flush;
    int result = soln.majorityElement2(test.first);
    cout << result << endl;
    assert(result == test.second);
  }
}


#include "ThreeSum.h"
#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  ThreeSum soln;
  vector<pair<vector<int>, vector<int>>> testcases = {
    {{}, {}},
    {{-1, 0, 1}, {-1, 0, 1}},
  };

  for (auto test : testcases) {
    cout << "input:\t";
    prettyPrint(test.first);
    cout << "output: " << endl;
    vector<vector<int>> result = soln.threeSum(test.first);
    for (auto triplet : result) {
      cout << "\t";
      prettyPrint(triplet);
    }
  }
}


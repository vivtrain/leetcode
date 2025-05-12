#include "ThreeSum.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  ThreeSum soln;
  vector<vector<int>> testcases = {
    {},
    {0, 0, 0},
    {-1, 0, 1},
    {0, 0, 0, 0},
    {-1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {-1, 0, 1, 2, -1, -4},
    {0, -1, 1, -2, 2, 3, -4},
  };

  for (auto test : testcases) {
    cout << "input:\t";
    prettyPrint(test);
    cout << "output: " << endl;
    vector<vector<int>> result = soln.threeSum(test);
    for (auto triplet : result) {
      cout << "\t";
      prettyPrint(triplet);
    }
    cout << endl;
  }
}


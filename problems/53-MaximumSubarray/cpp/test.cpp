#include "MaximumSubarray.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  MaximumSubarray soln;
  vector<vector<int>> testCases = {
    { },
    { -1 },
    { 1 },
    { 1, 2 },
    { -1, 2 },
    { 1, -2 },
    { 3, -2, 1 },
    { 3, -2, 1, 3 },
  };

  for (auto test : testCases) {
    cout << prettyString(test) << " -> " << soln.maxSubArray(test) << endl;
  }
}


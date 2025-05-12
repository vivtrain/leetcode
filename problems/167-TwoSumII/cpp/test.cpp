#include "TwoSumII.h"
#include <algorithm>
#include <iostream>
#include <cassert>
#include <tuple>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  TwoSumII soln;
  vector<tuple<vector<int>, int, vector<int>>> testCases {
    { vector<int>{}, 0, vector<int>{} },
    { {0}, 0, vector<int>{} },
    { {0, 0}, 0, {1, 2} },
    { {0, 1}, 0, {} },
    { {0, 1}, 1, {1, 2} },
    { {0, 1, 2}, 2, {1, 3} },
    { {-4, -3, -1, 0, 1, 2}, 0, {3, 5} },
    { {-4, -3, -1, 0, 1, 2}, -7, {1, 2} },
    { {-4, -3, -1, 0, 1, 2}, 3, {5, 6} },
    { {-4, -3, -1, 0, 1, 2}, -2, {1, 6} },
  };

  for (auto test : testCases) {
    vector<int> &numbers = get<0>(test);
    int &target = get<1>(test);
    vector<int> &answer = get<2>(test);

    vector<int> result = soln.twoSum(numbers, target);
    std::sort(answer.begin(), answer.end());
    std::sort(result.begin(), result.end());
    cout << prettyString(result) << " ?= " << prettyString(answer) << "\t";
    if (result == answer) {
      colorOut("PASS", colors::GREEN) << endl;
    } else {
      colorOut("FAIL", colors::RED) << endl;
    }

  }

}


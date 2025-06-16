#include "CombinationSum.h"
#include "colors.h"
#include <algorithm>
#include <string>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector< tuple< vector<int>, int, vector<vector<int>> > > testCases {
    { vector<int>(), 0, vector<vector<int>>() },
    { {2}, 1, vector<vector<int>>() },
    { {2}, 2, {{2}} },
    { {2}, 3, vector<vector<int>>() },
    { {2}, 4, {{2,2}} },
    { {2}, 5, vector<vector<int>>() },
    { {2}, 6, {{2,2,2}} },
    { {2,3}, 4, {{2,2}} },
    { {2,3}, 5, {{2,3}} },
    { {2,3}, 6, {{2,2,2},{3,3}} },
    { {2,3,5}, 8, {{2,2,2,2},{2,3,3},{3,5}} },
  };

  for (auto &[candidates, target, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(candidates) + ", " + to_string(target)) << " => ";
    for (auto &v : answer)
      cout << prettyString(v) << ", ";
    cout << endl;
    vector<vector<int>> result = soln.combinationSum3(candidates, target);
    for (auto &v : result)
      cout << prettyString(v) << ", ";
    cout << endl;
  }
}


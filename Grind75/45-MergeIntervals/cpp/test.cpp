#include "MergeIntervals.h"
#include "colors.h"
#include <set>
#include <utility>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases {
    { {}, {} },
    { {{1,2}}, {{1,2}} },
    { {{1,2},{1,3}}, {{1,3}} },
    { {{1,3},{1,2}}, {{1,3}} },
    { {{1,2},{0,3}}, {{0,3}} },
    { {{1,2},{1,3},{4,5}}, {{1,3},{4,5}} },
  };

  for (auto &[intervals, merged] : testCases) {
    colorOut(LIGHT_BLUE, prettyString2D(intervals, ",", "->")) << endl;
    vector<vector<int>> result = soln.merge(intervals);
    bool good = merged.size() == result.size();
    if (good) {
      for (size_t i = 0; i < merged.size(); i++) {      
        set<vector<int>> mergedSet, resultSet;
        mergedSet.insert(merged.begin(), merged.end());
        resultSet.insert(result.begin(), result.end());
        if (mergedSet != resultSet) {
          good = false;
          break;
        }
      }
    }
    colorOut(WHITE, prettyString2D(merged, ",", "->")) << endl;
    colorOut(good ? GREEN : RED, prettyString2D(result, ",", "->")) << endl;
  }
}


#include "Subsets.h"
#include <set>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<int>, vector<vector<int>>>> testCases {
    { {}, {{}} },
    { {1}, {{},{1}} },
    { {1,2}, {{},{1},{2},{1,2}} },
    { {1,2,3}, {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}} },
  };
  for (auto &[nums, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(nums)) << endl;
    colorOut(WHITE, prettyString2D(answer, ", ", ",")) << endl;
    vector<vector<int>> result = soln.subsets(nums);
    set<set<int>> setAnswer, setResult;
    for (const vector<int> &subset : answer) {
      set<int> setSubset(subset.begin(), subset.end());
      setAnswer.insert(setSubset);
    }
    for (const vector<int> &subset : result) {
      set<int> setSubset(subset.begin(), subset.end());
      setResult.insert(setSubset);
    }
    const char *good = setResult == setAnswer ? GREEN : RED;
    colorOut(good, prettyString2D(result, ", ", ",")) << endl;;
  }
}


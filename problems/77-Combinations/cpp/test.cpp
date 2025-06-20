#include "Combinations.h"
#include <set>
#include <tuple>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  vector<tuple<int, int, vector<vector<int>>>> testCases {
    { 0, 0, { {} } },
    { 0, 1, { } },
    { 1, 1, { {1} } },
    { 1, 2, { } },
    { 2, 1, { {1},{2}} },
    { 3, 2, { {1,2},{1,3},{2,3}} },
    { 4, 2, { {1,2},{1,3},{1,4},{2,3},{2,4},{3,4}} },
  };
  Solution soln;
  for (auto &[n, k, combinations] : testCases) {
    colorOut(LIGHT_BLUE, n, " choose ", k) << endl;
    colorOut(WHITE, prettyString2D(combinations, ",", ",")) << endl;
    vector<vector<int>> result = soln.combine(n, k);
    bool good = result.size() == combinations.size();
    if (good) {
      set<set<int>> setResult, setComb;
      for (size_t i = 0; i < result.size(); i++) {
        set<int> c, r;
        c.insert(combinations[i].begin(), combinations[i].end());
        setComb.insert(c);
        r.insert(result[i].begin(), result[i].end());
        setResult.insert(r);
      }
      good = setResult == setComb;
    }
    colorOut(good ? GREEN : RED, prettyString2D(result, ",", ",")) << endl;
  }
}


#include "Permutations.h"
#include "colors.h"
#include <ios>
#include <vector>
#include <set>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<vector<int>, vector<vector<int>>>> testCases {
    { {}, {{}} },
    { {1}, {{1}} },
    { {1,2}, {{1,2},{2,1}} },
    { {1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}} },
  };

  for (auto &[nums, perms] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(nums)) << endl;
    set<vector<int>> answer;
    colorOut(WHITE, "{ ");
    for (vector<int> &p : perms) {
      colorOut(WHITE, prettyString(p)) << " ";
      answer.insert(p);
    }
    colorOut(WHITE, "}") << endl;
    cout << "{ ";
    vector<vector<int>> result = soln.permute(nums);
    bool good = true;
    for (vector<int> &p : result) {
      cout << prettyString(p) << " ";
      good &= (answer.find(p) != answer.end());
    }
    cout <<  "} ";
    if (good)
      colorOut(GREEN, "✓") << endl;
    else 
      colorOut(RED, "✗") << endl;
  }
}


#include "Combinations.h"
#include <prettyPrint.h>
#include <vector>

using namespace std;

vector<vector<int>> Solution::combine(int n, int k) {
  vector<vector<int>> combinations;
  vector<int> comb;
  combine(n, k, comb, combinations);
  return combinations;
}

void Solution::combine(
    int nLeft,
    int kLeft,
    vector<int> &comb,
    vector<vector<int>> &combinations) {
  if (kLeft > nLeft)
    return;
  if (kLeft == 0) {
    combinations.push_back(comb);
    return;
  }
  for (int n = nLeft; n > 0; n--) {
    comb.push_back(n);
    combine(n - 1, kLeft - 1, comb, combinations);
    comb.pop_back();
  }
}

#include "Subsets.h"
#include <vector>

using namespace std;

vector<vector<int>> Solution::subsets(vector<int>& nums) {
  vector<vector<int>> powerSet { {} };
  for (const int &n : nums) {
    size_t nSubsetsBefore = powerSet.size();
    for (size_t s = 0; s < nSubsetsBefore; s++) {
      vector<int> newSubset(powerSet[s]);
      newSubset.push_back(n);
      powerSet.push_back(newSubset);
    }
  }
  return powerSet;
}


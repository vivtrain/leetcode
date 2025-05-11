#include "ThreeSum.h"
#include <cstddef>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums) {
  if (nums.size() < 3)
    return {{}};

  vector<vector<int>> result;
  vector<vector<bool>> repeats(nums.size(), vector<bool>(nums.size(), false));

  unordered_map<int, size_t> lookup;
  for (size_t i = 0; i < nums.size(); i++)
    lookup[nums[i]] = i;

  for (size_t i = 0; i < nums.size(); i++) {
    for (size_t j = i+1; j < nums.size(); j++) { 
      int leftover = 0 - (nums[i] + nums[j]);
      auto found = lookup.find(leftover);
      if (found != lookup.end()) {
        size_t k = found->second;
        if (i == k || j == k)
          continue;
        if (!repeats[i][j]) {
          result.push_back({{nums[i], nums[j], found->first}});
          repeats[i][j] = true;
          repeats[i][k] = true;
          repeats[j][i] = true;
          repeats[j][k] = true;
          repeats[k][i] = true;
          repeats[k][j] = true;
        }
      }
    }
  }
  return result;
}


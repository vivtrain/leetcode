#include "ThreeSum.h"
#include <cstddef>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums) {
  unordered_map<int, size_t> lookup;
  vector<vector<int>> result;
  for (size_t i = 0; i < nums.size(); i++)
    lookup[nums[i]] = i;
  for (size_t i = 0; i < nums.size(); i++) {
    for (size_t j = i+1; j < nums.size(); j++) {
      int leftover = 0 - (nums[i] + nums[j]);
      auto found = lookup.find(leftover);
      if (found != lookup.end()) {
        result.push_back({{nums[i], nums[j], found->first}});
      }
    }
  }
  return result;
}

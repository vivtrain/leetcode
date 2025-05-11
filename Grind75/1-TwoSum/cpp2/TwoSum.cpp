#include "TwoSum.h"
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> TwoSum::twoSum(std::vector<int>& nums, int target) {
  if (nums.size() < 2)
    return {};
  unordered_map<int, int> indices;
  for (int i = 0; i < static_cast<int>(nums.size()); i++) {
    int leftover = target - nums[i];
    auto found = indices.find(leftover);
    if (found != indices.end() && found->second != i) {
      return {i, found->second};
    } else {
      indices[nums[i]] = i;
    }
  }
  return {};
}


#include "TwoSum.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> TwoSum::twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hashMap;
  for (int index = 0; index < int(nums.size()); index++) {
    int n = nums[index];
    auto searched = hashMap.find(target-n);
    if (searched == hashMap.end())
      hashMap[n] = index;
    else
      return std::vector<int>{index, searched->second};
  }
  return std::vector<int>();
}

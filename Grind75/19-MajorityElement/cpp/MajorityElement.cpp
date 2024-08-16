#include "MajorityElement.h"
#include <vector>
#include <unordered_map>

int MajorityElement::majorityElement(std::vector<int>& nums) {
  std::unordered_map<int, size_t> numCounts;
  for (int num : nums)
    numCounts[num]++;
  size_t max = 0;
  int majorityNum;
  for (auto numCount : numCounts) {
    if (numCount.second > max) {
      max = numCount.second;
      majorityNum = numCount.first;
    }
  }
  return majorityNum;
}

int MajorityElement::majorityElement2(std::vector<int>& nums) {
  int majorityNum = nums[0];
  int majorityCount = 0;
  for (int num : nums) {
    if (num == majorityNum) {
      majorityCount++;
    } else {
      majorityCount--;
      if (majorityCount < 0) {
        majorityNum = num;
        majorityCount = 1;
      }
    }
  }
  return majorityNum;
}


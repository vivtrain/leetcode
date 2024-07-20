#include "BinarySearch.h"
#include <iostream>

int BinarySearch::search(std::vector<int>& nums, int target) {
  if (nums.empty())
    return -1;
  if (target < nums[0])
    return -1;
  if (target > nums.back())
    return -1;
  
  int index = nums.size()/2;
  int jump = nums.size()-1;
  while (jump != 0) {
    if (index > int(nums.size()-1) || index < 0)
      return -1;
    if (nums[index] == target)
      return index;
    jump /= 2;
    if (nums[index] < target)
      index += jump;
    else
      index -= jump;
  }
  return -1;
}


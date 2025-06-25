#include "SortColors.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void Solution::sortColors(vector<int>& nums) {
  if (nums.size() < 2)
    return;
  int left = 0, right = nums.size()-1, index = 0;
  while (left <= index && index <= right) {
    if (nums[index] == 0) {
      std::swap(nums[index], nums[left]);
      left++;
    } else if (nums[index] == 2) {
      std::swap(nums[index], nums[right]);
      right--;
    }
    if (nums[index] == 1 || index < left)
      index++;
  }
}

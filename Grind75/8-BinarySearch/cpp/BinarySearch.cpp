#include "BinarySearch.h"

int BinarySearch::search_recurse(std::vector<int>& nums, int target, int i,
    int j) {
  if (j < i)
    return -1;
  int pivot = i + (j-i)/2;
  if (nums[pivot] == target)
    return pivot;
  else if(nums[pivot] > target)
    return search_recurse(nums, target, i, pivot-1);
  else
    return search_recurse(nums, target, pivot+1, j);
}

int BinarySearch::search(std::vector<int>& nums, int target) {
  return search_recurse(nums, target, 0, nums.size()-1);
}

int BinarySearch::search_it(std::vector<int>& nums, int target) {
  int i = 0, j = nums.size()-1;
  while (i <= j) {
    int pivot = i + (j-i)/2;
    if (nums[pivot] == target)
      return pivot;
    if (nums[pivot] > target)
      j = pivot-1;
    else
      i = pivot+1;
  }
  return -1;
}



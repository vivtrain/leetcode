#include "SearchRotatedArray.h"
#include <iostream>
#include <vector>

using namespace std;

int Solution::search(vector<int>& nums, int target) {
  // Trivial cases
  int N = nums.size();
  if (N == 0)
    return -1;
  if (N == 1)
    return (nums[0] == target) ? 0 : -1;
  if (nums[0] == target)
    return 0;

  if (nums[0] < nums[N-1])
    return searchNotRotated(nums, 0, N-1, target);

  // Find pivot using binary search
  int pivot = 1;
  int step = N;
  while (nums[pivot-1] < nums[pivot]) {
    if (nums[pivot] < nums[0])
      pivot -= step;
    else if (nums[pivot] > nums[0])
      pivot += step;
    else
      pivot++;
    step = max(step/2, 1);
    pivot = min(max(1, pivot), N-1);
  }
  // cout << "pivot at index: " << pivot << " holding " << nums[pivot] << endl;

  // Binary search within whichever half is appropriate
  if (nums[0] <= target && target <= nums[pivot-1])
    return searchNotRotated(nums, 0, pivot-1, target);
  else if (nums[pivot] <= target && target <= nums[N-1])
    return searchNotRotated(nums, pivot, N-1, target);
  else
    return -1;
}

int Solution::searchNotRotated(
    vector<int>& nums,
    int lowerBound,
    int upperBound,
    int target) {
  // cout << "searching between nums[" << lowerBound << "]==" << nums[lowerBound]
  //   << " and nums[" << upperBound << "]==" << nums[upperBound] << endl;
  if (lowerBound > upperBound)
    return -1;
  int center = (upperBound + lowerBound) / 2;
  if (nums[center] < target)
    lowerBound = center + 1;
  else if (target < nums[center])
    upperBound = center -1;
  else
    return center;
  return searchNotRotated(nums, lowerBound, upperBound, target);
}

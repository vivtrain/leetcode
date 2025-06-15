#include "SearchRotatedArray.h"
#include <iostream>
#include <vector>

using namespace std;


int Solution::search(std::vector<int>& nums, int target) {
  int N = nums.size();
  if (N == 0)
    return -1;
  int left = 0, right = N-1;

  while (left <= right) {
    int center = (left + right) / 2;
    // Ensure pointers are accounted for
    if (nums[left] == target) return left;
    if (nums[right] == target) return right;
    if (nums[center] == target) return center;
    // Recurse on left or right depending on where pivot is
    if (nums[left] < nums[center]) { // left side is sorted
      if (target > nums[center] || target < nums[left])
        left = center + 1; // check the right side
      else
        right = center - 1; // check the left side
    } else { // right side is sorted
      if (target < nums[center] || target > nums[right])
        right = center - 1; // check the left side
      else
        left = center + 1; // check the right side
    }
  }
  return -1;
}

int Solution::search3_recurse(std::vector<int>& nums,
    int lower, int upper, int target) {
  if (lower > upper) return -1;
  int center = (lower + upper) / 2;

  if (nums[lower] == target) return lower;
  if (nums[upper] == target) return upper;
  if (nums[center] == target) return center;

  cout << lower << " " << upper << endl;
  bool leftSorted = nums[lower] < nums[center];
  bool targetOnLeft = nums[lower] < target && target < nums[center];
  bool targetOnRight = nums[center] < target && target < nums[upper];

  if (leftSorted) {
    if (targetOnLeft)
      return search3_recurse(nums, lower, center-1, target);
    else
      return search3_recurse(nums, center+1, upper, target);
  } else {
    if (targetOnRight)
      return search3_recurse(nums, center+1, upper, target);
    else
      return search3_recurse(nums, lower, center-1, target);
  }
}

int Solution::search3(vector<int>& nums, int target) {
  cout << endl;
  int N = nums.size();
  if (N == 0)
    return -1;
  return search3_recurse(nums, 0, N-1, target);
}

int Solution::search2(vector<int>& nums, int target) {
  // Trivial cases
  int N = nums.size();
  if (N == 0)
    return -1;
  if (N == 1)
    return (nums[0] == target) ? 0 : -1;
  if (nums[0] == target)
    return 0;

  if (nums[0] < nums[N-1])
    return binarySearch(nums, 0, N-1, target);

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
    return binarySearch(nums, 0, pivot-1, target);
  else if (nums[pivot] <= target && target <= nums[N-1])
    return binarySearch(nums, pivot, N-1, target);
  else
    return -1;
}

int Solution::binarySearch(
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
  return binarySearch(nums, lowerBound, upperBound, target);
}

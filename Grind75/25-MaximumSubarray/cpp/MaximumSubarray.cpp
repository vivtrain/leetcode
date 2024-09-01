#include "MaximumSubarray.h"
#include <vector>

inline int _max(const int &a, const int &b) {
  return (a > b) ? a : b;
}

int MaximumSubarray::maxSubArray(std::vector<int>& nums) {
  int bestSum = nums[0], curSum = 0;
  for (int n : nums) {
    if (n > curSum + n)
      curSum = n;
    else
      curSum += n;
    bestSum = _max(bestSum, curSum);
  }
  return bestSum;
}


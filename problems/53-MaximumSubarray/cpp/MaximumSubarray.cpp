#include "MaximumSubarray.h"
#include <vector>

using namespace std;

int MaximumSubarray::maxSubArray(vector<int> &nums) {
  if (nums.size() < 1)
    return 0;
  int bestSum = nums[0];
  int prefixSum = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    if (prefixSum < 0)
      prefixSum = 0;
    int curSum = prefixSum + nums[i];
    if (curSum > bestSum)
      bestSum = curSum;
    prefixSum = curSum;
  }
  return bestSum;
}

#include "PartitionEqualSubsetSum.h"
#include <prettyPrint.h>
#include <vector>

using namespace std;

bool Solution::canPartition(vector<int>& nums) {
  int totalSum = 0;
  for (const int &n : nums)
    totalSum += n;
  if (totalSum % 2 == 1)
    return false;
  int target = totalSum / 2;
  vector<bool> possibleSums(target + 1);
  possibleSums[0] = true;
  for (const int &num : nums) {
    for (int p = target; p >= 0; p--) {
      if (possibleSums[p] && p + num <= target)
        possibleSums[p + num] = true;
    }
  }
  return possibleSums.back();
}


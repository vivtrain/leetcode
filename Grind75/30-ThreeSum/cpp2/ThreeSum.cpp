#include "ThreeSum.h"
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums) {
  if (nums.size() < 3)
    return {{}};
  vector<vector<int>> results;

  std::sort(nums.begin(), nums.end());

  for (size_t i = 0; i < nums.size()-1; i++) {
    if (i > 0 && nums[i-1] == nums[i])
      continue;
    
    for (size_t j=i+1, k=nums.size()-1; j < k;) {
      int threeSum = nums[i] + nums[j] + nums[k];
      if (j > i+1 && j < k && nums[j] == nums[j-1]) {
        j++;
        continue;
      }
      if (threeSum < 0) {
        j++;
      } else if (threeSum > 0) {
        k--;
      } else {
        results.push_back({nums[i], nums[j], nums[k]});
        j++;
      }
    }
  }

  return results;
}


#include "ContainsDuplicate.h"
#include <vector>
#include <unordered_set>

bool ContainsDuplicate::containsDuplicate(std::vector<int>& nums) {
  std::unordered_set<int> found(nums.size());
  for (int n : nums) {
    if (found.find(n) != found.end())
      return true;
    else
      found.insert(n);
  }
  return false;
}


#include "TwoSum.h"
#include <vector>
#include <unordered_set>
#include <algorithm>

// Method 1: Sort and Iterate
// Space: O(n), could be O(1) if we can sort the input array in place
// Time: O(n*log(n)), bound by sorting
std::vector<int> TwoSum::twoSum_sort(std::vector<int>& nums, int target) {
  // Create a sorted array and instantiate two iterators at each end
  std::vector<int> sorted(nums);
  std::sort(sorted.begin(), sorted.end());
  std::vector<int>::iterator i = sorted.begin(), j = sorted.end()-1;
  // If current sum is too small, increment first iterator
  // If current sum is too large, decrement last iterator
  // If you find the sum, return it
  // If you don't find the sum, return empty
  while (i != j) {
    int sum = *i + *j;
    if (sum < target)
      i++;
    else if (sum > target)
      j--;
    else
      return std::vector<int>({*i, *j});
  }
  return std::vector<int>();
}

// Method 2: Hash Set Lookup
// Space: O(n) for the hash set
// Time: O(n), i.e. at most n lookups of O(1)
std::vector<int> TwoSum::twoSum(std::vector<int>& nums, int target) {
  // Construct an empty hash set
  std::unordered_set<int> hashSet;
  // Loop through array, if you find it's complement, return it
  // If the complement doesn't exist, add the element to the hash set
  // If you never find the complement, return empty
  for (int n : nums) {
    std::unordered_set<int>::iterator search = hashSet.find(target-n);
    if (search != hashSet.end())
      return std::vector<int>({n, target-n});
    else
      hashSet.insert(n);
  }
  return std::vector<int>();
}

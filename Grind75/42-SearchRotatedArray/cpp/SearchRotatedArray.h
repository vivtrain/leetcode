#ifndef SEARCH_ROTATED_ARRAY
#define SEARCH_ROTATED_ARRAY

#include <vector>

class Solution {
  public:
    int search(std::vector<int>& nums, int target);
    int search2(std::vector<int>& nums, int target);
    int search3(std::vector<int>& nums, int target);
  private:
    int binarySearch(std::vector<int>& nums, int lowerBound, int upperBound, int target);
    int search3_recurse(std::vector<int>& nums, int lowerBound, int upperBound, int target);
};

#endif


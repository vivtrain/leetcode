#ifndef SEARCH_ROTATED_ARRAY
#define SEARCH_ROTATED_ARRAY

#include <vector>

class Solution {
  public:
    int search(std::vector<int>& nums, int target);
  private:
    int searchNotRotated(std::vector<int>& nums, int lowerBound, int upperBound, int target);
};

#endif


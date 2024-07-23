#ifndef BINARY_SEARCH
#define BINARY_SEARCH

#include <vector>

class BinarySearch {
  public:
    int search(std::vector<int>& nums, int target);
    int search_it(std::vector<int>& nums, int target);
  private:
    int search_recurse(std::vector<int>& nums, int target, int i, int j);
};

#endif


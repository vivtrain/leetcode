#ifndef PERMUTATIONS
#define PERMUTATIONS

#include <vector>
#include <queue>

class Solution {
  public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums);
  private:
    void permute(
        std::queue<int>& nums,
        std::vector<int>& perm,
        std::vector<std::vector<int>>& permutations);
};

#endif


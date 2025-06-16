#ifndef COMBINATION_SUM
#define COMBINATION_SUM

#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combinationSum(
        std::vector<int>& candidates,
        int target);
    std::vector<std::vector<int>> combinationSum2(
        std::vector<int>& candidates,
        int target);
    std::vector<std::vector<int>> combinationSum3(
        std::vector<int>& candidates,
        int target);
  private:
    std::vector<std::vector<int>> combinationSum2_recurse(
        const std::vector<int>& candidates,
        const size_t index,
        const int target);
    void combinationSum3_recurse(
        const std::vector<int>& candidates,
        const size_t index,
        const int target,
        std::vector<std::vector<int>>& results);
};

#endif


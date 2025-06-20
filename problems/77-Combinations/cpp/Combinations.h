#ifndef COMBINATIONS
#define COMBINATIONS

#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> combine(int n, int k);
  private:
    void combine(
        int nLeft,
        int kLeft,
        std::vector<int> &comb,
        std::vector<std::vector<int>> &combinations);
};

#endif


#ifndef CLIMBING_STAIRS
#define CLIMBING_STAIRS

#include <vector>

class ClimbingStairs {
  public:
    int climbStairs(int n);
    int climbStairs_naive(int n);
    int climbStairs_memoized(int n);
  private:
    std::vector<int> memo;
};

#endif


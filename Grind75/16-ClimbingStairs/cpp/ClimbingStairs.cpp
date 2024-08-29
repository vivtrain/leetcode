#include "ClimbingStairs.h"
#include <cassert>

int ClimbingStairs::climbStairs(int n) {
  if (n == 0)
    return 1;
  int prev = 0, num = 1, sum = 0;
  for (int i = 0; i < n; i++) {
    sum = prev + num;
    prev = num;
    num = sum;
  }
  return sum;
}

int ClimbingStairs::climbStairs_naive(int n) {
  if (n <= 0)
    return 1;
  else if (n == 1)
    return 1;
  else
    return climbStairs_naive(n-1) + climbStairs_naive(n-2);
}

int ClimbingStairs::climbStairs_memoized(int n) {
  if (n >=0 && memo.size() < n+1)
    memo.resize(n+1);
  if (n <= 1) {
    memo[0] = memo[1] = 1;
    return 1;
  } else {
    if (memo[n-1] == 0)
      memo[n-1] = climbStairs_memoized(n-1);
    if (memo[n-2] == 0)
      memo[n-2] = climbStairs_memoized(n-2);
    return memo[n-1] + memo[n-2];
  }
}


#include "ClimbingStairs.h"

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

int ClimbingStairs::climbStairs_recursive(int n) {
  if (n <= 0)
    return 1;
  else if (n == 1)
    return 1;
  else
    return climbStairs_recursive(n-1) + climbStairs_recursive(n-2);
}


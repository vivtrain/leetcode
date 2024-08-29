#include "ClimbingStairs.h"
#include <iostream>
#include <cassert>
#include <Time.h>

int main() {
  ClimbingStairs soln;
  int N = 47; // Largest Fibonacci number that fits in int32

  auto start0 = Time::now();
  std::cout << soln.climbStairs(N) << std::endl;
  std::cout << "O(1) memo: " << Time::elapsed_millis(start0) << "ms" << std::endl;

  auto start1 = Time::now();
  std::cout << soln.climbStairs_memoized(N) << std::endl;
  std::cout << "Memoized: " << Time::elapsed_millis(start1) << "ms" << std::endl;

  auto start2 = Time::now();
  std::cout << soln.climbStairs_naive(N) << std::endl;
  std::cout << "Naive recursion: " << Time::elapsed(start2) << "s" << std::endl;
}


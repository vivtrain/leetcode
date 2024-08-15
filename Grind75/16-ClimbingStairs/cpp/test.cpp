#include "ClimbingStairs.h"
#include <iostream>
#include <cassert>

int main() {
  ClimbingStairs soln;
  // The solution is just the nth Fibonacci number
  for (int i = 0; i < 10; i++) {
    std::cout << soln.climbStairs_recursive(i) << std::endl;
  }
}


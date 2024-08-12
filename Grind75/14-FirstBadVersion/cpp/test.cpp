#include "FirstBadVersion.h"
#include <iostream>
#include <cassert>

int main() {
  FirstBadVersion soln;

  for (int n = 1; n <= 10; n++) {
    soln.n = n;
    std::cout << '\n';
    for (int i = 1; i <= n; i++)
      std::cout << i << ' ';
    std::cout << std::endl;
    for (int bad = 1; bad <= n; bad++) {
      soln.bad = bad;
      std::cout << "bad should be " << bad << std::flush;
      int result = soln.firstBadVersion(n);
      std::cout << ", got " << result << std::endl;;
      assert(result == bad);
    }
  }
  std::cout << "TESTS PASSED!" << std::endl;
}


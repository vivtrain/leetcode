#include "ContainsDuplicate.h"
#include <ios>
#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <prettyPrint.h>

int main() {
  ContainsDuplicate soln;
  std::vector<std::pair<std::vector<int>, bool>> testCases {
    {{}, false},
    {{0}, false},
    {{1,2}, false},
    {{1,2,3}, false},
    {{1,2,2}, true},
    {{1,2,2,1}, true},
  };

  for (auto test : testCases) {
    std::cout << prettyString(test.first) << " contains a duplicate: "
      << std::boolalpha << test.second << " ==? " << std::flush;
    bool res = soln.containsDuplicate(test.first);
    std::cout << std::boolalpha << res << std::endl;
    assert(res == test.second);
  }
  std::cout << "TESTS PASSED!" << std::endl;
}


#include "ReverseLinkedList.h"
#include <iostream>
#include <cassert>
#include <List.h>
#include <vector>
#include <tuple>
#include <string>
#include <exception>

int main() {
  using namespace std;
  using namespace List;
  ReverseLinkedList soln;

  vector<pair<vector<int>, vector<int>>> testCases {
    {{},{}},
    {{1},{1}},
    {{1,2},{2,1}},
    {{1,2,3},{3,2,1}},
    {{1,2,3,4},{4,3,2,1}},
  };

  for (auto test : testCases) {
    ListNode *fwd = makeList(test.first), *rev = makeList(test.second);
    cout << "Reverse of " << strList(fwd) << " should be " << strList(rev)
      << flush;
    ListNode *result;
    try {
      result = soln.reverseList(fwd);
      cout << "\n\tis " << strList(result) << endl;
      assert(listEquals(rev, result));
    } catch(std::exception e) {
      cout << e.what() << endl;
      freeList(result); // TODO: Memory leaks if list ends up in unusable state
      freeList(rev);
      cout << "TEST FAILED!" << endl;
      exit(1);
    }
    freeList(result);
    freeList(rev);
  }
  cout << "TESTS PASSED!" << endl;
}


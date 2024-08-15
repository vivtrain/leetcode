#include "ReverseLinkedList.h"
#include <iostream>
#include <cassert>
#include <List.h>
#include <vector>
#include <tuple>
#include <string>

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
    ListNode *result = soln.reverseList_recursive(fwd);
    cout << "\n\tis " << strList(result) << endl;
    assert(listEquals(rev, result));
  }
  cout << "TESTS PASSED!" << endl;
}


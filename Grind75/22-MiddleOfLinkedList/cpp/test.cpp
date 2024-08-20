#include "MiddleOfLinkedList.h"
#include <iostream>
#include <cassert>
#include <List.h>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  using namespace List;
  MiddleOfLinkedList soln;
  vector<pair<ListNode*, ListNode*>> testCases;

  testCases.push_back(make_pair(nullptr, nullptr));

  for (int i = 1; i <= 10; i++) {
    int middle = i/2 + 1;
    vector<int> values(i);
    for (int n = 0; n < i; n++)
      values[n] = n;
    ListNode *lst = makeList(values);
    testCases.push_back(make_pair(lst, atIndex(lst, middle-1)));
  }

  for (auto test : testCases) {
    printList(test.first);
    if (test.second)
      cout << "\tMiddle should be " << test.second->val << ", got " << flush;
    else
      cout << "\tNo middle, should get NULL" << ", got " << flush;
    ListNode *result = soln.middleNode(test.first);
    if (!result)
      cout << "NULL" << endl;
    else
      cout << result->val << endl;
    assert(result == test.second);
    freeList(test.first);
  }
  cout << "TESTS PASSED!" << endl;
}


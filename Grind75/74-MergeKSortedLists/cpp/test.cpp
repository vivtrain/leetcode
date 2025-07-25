#include "MergeKSortedLists.h"
#include "colors.h"
#include <prettyPrint.h>
#include <List.h>
#include <utility>
#include <vector>

using namespace std;
using namespace colors;
using namespace List;

int main() {
  Solution soln;
  vector<pair<vector<ListNode*>, ListNode*>> testCases {
    { {},
      makeList({}) },
    { { makeList({}),
        makeList({}) },
      makeList({}) },
    { { makeList({1}),
        makeList({}) },
      makeList({1}) },
    { { makeList({1}),
        makeList({2}) },
      makeList({1,2}) },
    { { makeList({1}),
        makeList({2,3}) },
      makeList({1,2,3}) },
    { { makeList({1,3}),
        makeList({2}) },
      makeList({1,2,3}) },
    { { makeList({1,3,5}),
        makeList({2,4,6}),
        makeList({0,4,7}) },
      makeList({0,1,2,3,4,4,5,6,7}) },
  };

  for (auto &[lists, answer] : testCases) {
    cout << LIGHT_BLUE << "Merge:" << LIGHT_CYAN << endl;
    for (const auto &l : lists)
      printList(l);
    cout << LIGHT_BLUE << "Into: " << LIGHT_CYAN << endl;
    printList(answer);
    ListNode *result = soln.mergeKLists(lists);
    cout << (listEquals(result, answer) ? GREEN : RED);
    printList(result);
    cout << NO_COLOR << endl;
  }
}


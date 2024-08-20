#include "LinkedListCycle.h"
#include <iostream>
#include <cassert>
#include <List.h>

int main() {
  LinkedListCycle soln;
  List::ListNode *circ = List::makeList({1,2,3,4});
  std::cout << std::boolalpha << soln.hasCycle(circ) << std::endl;
  List::tail(circ)->next = circ;
  std::cout << std::boolalpha << soln.hasCycle_hashset(circ) << std::endl;

  List::ListNode *node = List::atIndex(circ, 3);
  node->next = nullptr;
  List::freeList(circ);
}


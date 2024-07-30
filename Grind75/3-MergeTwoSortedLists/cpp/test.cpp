#include "MergeTwoSortedLists.h"
#include <iostream>
#include <vector>
#include <List.h>

int main() {
  MergeTwoSortedLists m;
  List::ListNode *list1 = List::makeList({1,2,3,4,5});
  List::ListNode *list2 = List::makeList({2,4,6,8,10});
  List::ListNode *list3 = m.mergeTwoSortedLists3(list1, list2);
  List::printList(list3);
  List::freeList(list3);
}


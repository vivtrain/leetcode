#include "MergeTwoSortedLists.h"
#include <iostream>
#include <vector>

void printList(ListNode *list) {
  while (list) {
    std::cout << list->val << " -> ";
    list = list->next;
  }
  std::cout << '.' << std::endl;
}

ListNode* makeList(std::vector<int> values) {
  ListNode *head = nullptr, *node = nullptr, *prev = nullptr;
  for (int v : values) {
    node = new ListNode(v);
    if (!head)
      head = node;
    if (prev)
      prev->next = node;
    prev = node;
  }
  return head;
}

void freeList(ListNode *list) {
  ListNode *next;
  while (list) {
    next = list->next;
    free(list);
    list = next;
  }
}


int main() {
  MergeTwoSortedLists m;
  ListNode *list1 = makeList({1,2,3,4,5});
  ListNode *list2 = makeList({2,4,6,8,10});
  ListNode *list3 = m.mergeTwoSortedLists3(list1, list2);
  printList(list3);
  freeList(list3);
}


#include <List.h> 
#include <iostream>

namespace List {

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

}


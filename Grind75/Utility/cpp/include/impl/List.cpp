#include <List.h> 
#include <iostream>

namespace List {

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

  void freeList(ListNode *lst) {
    ListNode *next;
    while (lst) {
      next = lst->next;
      free(lst);
      lst = next;
    }
  }

  void printList(ListNode *lst) {
    while (lst) {
      std::cout << lst->val << " -> ";
      lst = lst->next;
    }
    std::cout << '.' << std::endl;
  }

  ListNode* tail(ListNode *head) {
    ListNode *node = head, *prev = nullptr;
    while (node) {
      prev = node;
      node = node->next;
    }
    return prev;
  }

}


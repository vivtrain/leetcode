#include <List.h>
#include <iostream>
#include <string>

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
      delete lst;
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

  std::string strList(ListNode *lst) {
    std::string output;
    while (lst) {
      output += std::to_string(lst->val) + " -> ";
      lst = lst->next;
    }
    output += '.';
    return output;
  }

  ListNode* tail(ListNode *head) {
    ListNode *node = head, *prev = nullptr;
    while (node) {
      prev = node;
      node = node->next;
    }
    return prev;
  }

  bool listEquals(ListNode *l1, ListNode *l2) {
    while (l1 && l2) {
      if (l1->val != l2->val)
        return false;
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l1 || l2)
      return false;
    return true;
  }

  ListNode* atIndex(ListNode *lst, size_t index) {
    ListNode *node = lst;
    for (size_t i = 0; i < index; i++) {
      if (!node)
        return nullptr;
      node = node->next;
    }
    return node;
  }

}


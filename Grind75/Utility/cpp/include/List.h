#ifndef LIST
#define LIST

#include <vector>

namespace List {

  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* makeList(std::vector<int> values);
  void freeList(ListNode *list);
  void printList(ListNode *list);
  ListNode* tail(ListNode *head);
}

#endif


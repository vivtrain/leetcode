#ifndef LIST
#define LIST

#include <vector>
#include <string>

namespace List {

  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* makeList(std::vector<int> values);
  void freeList(ListNode *lst);
  void printList(ListNode *lst);
  std::string strList(ListNode *lst);
  ListNode* tail(ListNode *head);
  bool listEquals(ListNode *l1, ListNode *l2);
}

#endif


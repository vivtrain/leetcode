#include "ReverseLinkedList.h"
#include <List.h>

List::ListNode* ReverseLinkedList::reverseList(List::ListNode* head) {
  List::ListNode *node = head, *prev = nullptr;
  while (node) {
    List::ListNode *next = node->next;
    node->next = prev;
    prev = node;
    node = next;
  }
  return prev;
}


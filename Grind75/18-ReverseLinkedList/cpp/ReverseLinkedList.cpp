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

List::ListNode* ReverseLinkedList::reverseList_recursive(List::ListNode* head) {
  if (!head)
    return nullptr;
  if (!head->next)
    return head;
  List::ListNode *restOldHead = head->next;
  List::ListNode *restReversed = reverseList_recursive(head->next);
  restOldHead->next = head;
  head->next = nullptr;
  return restReversed;
}


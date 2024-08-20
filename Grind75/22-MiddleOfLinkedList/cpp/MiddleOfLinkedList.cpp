#include "MiddleOfLinkedList.h"
#include <List.h>

using namespace List;

ListNode* MiddleOfLinkedList::middleNode(ListNode* head) {
  if (!head)
    return nullptr;
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}


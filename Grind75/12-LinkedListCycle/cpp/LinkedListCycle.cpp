#include "LinkedListCycle.h"
#include <unordered_set>

bool LinkedListCycle::hasCycle(List::ListNode *head) {
  List::ListNode *slow = head;
  List::ListNode *fast = (head) ? head->next : nullptr;

  while (slow && fast) {
    if (slow == fast)
      return true;
    slow = slow->next;
    fast = fast->next;
    if (fast)
      fast = fast->next;
  }
  return false;
}

bool LinkedListCycle::hasCycle_hashset(List::ListNode *head) {
  List::ListNode *node = head;
  std::unordered_set<List::ListNode*> visited;
  while (node) {
    if (visited.find(node) != visited.end())
      return true;
    visited.insert(node);
    node = node->next;
  }
  return false;
}



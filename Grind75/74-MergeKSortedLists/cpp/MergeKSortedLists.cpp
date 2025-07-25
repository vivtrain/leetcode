#include "MergeKSortedLists.h"
#include <List.h>
#include <queue>
#include <vector>

using namespace std;
using namespace List;

struct cmpNodes {
  bool operator()(const ListNode* a, const ListNode* b) {
    return a->val > b->val;
  }
}; 

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
  ListNode *mergedHead = nullptr, *mergedTail = nullptr;
  priority_queue<ListNode*, vector<ListNode*>, cmpNodes> minHeap;
  for (ListNode* head : lists)
    if (head)
      minHeap.push(head);
  while (!minHeap.empty()) {
    ListNode *node = minHeap.top();
    minHeap.pop();
    if (!node)
      continue;
    if (node->next)
      minHeap.push(node->next);
    if (!mergedTail) {
      mergedHead = node;
      mergedTail = node;
    } else {
      mergedTail->next = node;
      mergedTail = mergedTail->next;
    }
  }
  return mergedHead;
}

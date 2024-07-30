#ifndef MERGE_TWO_SORTED_LISTS
#define MERGE_TWO_SORTED_LISTS

#include <List.h>

class MergeTwoSortedLists {
  public:
    List::ListNode* mergeTwoSortedLists(List::ListNode *list1, List::ListNode *list2);
    List::ListNode* mergeTwoSortedLists2(List::ListNode *list1, List::ListNode *list2);
    List::ListNode* mergeTwoSortedLists3(List::ListNode *list1, List::ListNode *list2);
    List::ListNode* mergeTwoSortedLists_recursive(List::ListNode *list1, List::ListNode *list2);
};

#endif


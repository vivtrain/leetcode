#ifndef MERGE_TWO_SORTED_LISTS
#define MERGE_TWO_SORTED_LISTS

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeTwoSortedLists {
  public:
    ListNode* mergeTwoSortedLists(ListNode *list1, ListNode *list2);
    ListNode* mergeTwoSortedLists2(ListNode *list1, ListNode *list2);
    ListNode* mergeTwoSortedLists3(ListNode *list1, ListNode *list2);
    ListNode* mergeTwoSortedLists_recursive(ListNode *list1, ListNode *list2);
};

#endif


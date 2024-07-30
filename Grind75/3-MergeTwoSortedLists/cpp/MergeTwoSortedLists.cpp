#include "MergeTwoSortedLists.h"

List::ListNode* MergeTwoSortedLists::mergeTwoSortedLists(List::ListNode *list1,
    List::ListNode *list2) {

  List::ListNode *list3 = nullptr;
  List::ListNode *head = list3;
  List::ListNode *prev = nullptr;

  while (true) {
    if (list1 && list2) {
      if (list1->val < list2->val) {
        list3 = list1;
        if (prev)
          prev->next = list3;
        list1 = list1->next;
      } else {
        list3 = list2;
        if (prev)
          prev->next = list3;
        list2 = list2->next;
      }
      if (!head)
        head = list3;
    } else if (!list2) {
      list3 = list1;
      if (!head)
        head = list3;
      if (prev)
        prev->next = list3;
      break;
    } else if (!list1) {
      list3 = list2;
      if (!head)
        head = list3;
      if (prev)
        prev->next = list3;
      break;
    } else {
      break;
    }
    prev = list3;
  }
  return head;
}

List::ListNode* MergeTwoSortedLists::mergeTwoSortedLists2(List::ListNode *list1,
    List::ListNode *list2) {

  List::ListNode *list3, *head;
  if (list1 && list2) {
    if (list1->val < list2->val) {
      list3 = list1;
      list1 = list1->next;
    } else {
      list3 = list2;
      list2 = list2->next;
    }
  } else if (list1)
    list3 = list1;
  else if (list2)
    list3 = list2;
  else
    return nullptr;
  head = list3;

  while (true) {
    if (list1 && list2) {
      if (list1->val < list2->val) {
        list3->next = list1;
        list1 = list1->next;
      } else {
        list3->next = list2;
        list2 = list2->next;
      }
      list3 = list3->next;
    } else if (list1) {
      list3->next = list1;
      break;
    } else if (list2) {
      list3->next = list2;
      break;
    } else {
      break;
    }
  }
  return head;
}

List::ListNode* MergeTwoSortedLists::mergeTwoSortedLists3(List::ListNode *list1,
    List::ListNode *list2) {

  if (!list2)
    return list1;
  if (!list1)
    return list2;

  List::ListNode *list3, *head;
  if (list1->val < list2->val) {
    list3 = list1;
    list1 = list1->next;
  } else {
    list3 = list2;
    list2 = list2->next;
  }
  head = list3;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      list3->next = list1;
      list1 = list1->next;
    } else {
      list3->next = list2;
      list2 = list2->next;
    }
    list3 = list3->next;
  }
  
  if (list1)
    list3->next = list1;
  else
    list3->next = list2;

  return head;
}

List::ListNode* MergeTwoSortedLists::mergeTwoSortedLists_recursive(List::ListNode *list1,
    List::ListNode *list2) {

  List::ListNode *list3;
  if (list1 && list2) {
    if (list1->val < list2->val) {
      list3 = list1;
      list3->next = mergeTwoSortedLists_recursive(list1->next, list2);
    } else {
      list3 = list2;
      list3->next = mergeTwoSortedLists_recursive(list1, list2->next);
    }
    return list3;
  } else if (list1) {
    return list1;
  } else if (list2) {
    return list2;
  } else {
    return nullptr;
  }
}


from __future__ import annotations
from typing import Optional

class ListNode:
  def __init__(self, val=0, nxt=None):
    self.val: int = val
    self.next: ListNode = nxt

def makeList(lst: Optional[list]) -> Optional[ListNode]:
  if not lst:
    return None
  head = ListNode(lst[0])
  node = head
  for i in range(1, len(lst)):
    node.next = ListNode(lst[i])
    node = node.next
  return head

def extractList(lst: Optional[ListNode]) -> list:
  extracted = []
  while lst is not None:
    extracted.append(lst.val)
    lst = lst.next
  return extracted

def printList(lst: Optional[list]) -> None:
  print('[', end='')
  while lst:
    print(lst.val, ', ' if lst.next else '', sep='', end='')
    lst = lst.next
  print(']')

def strList(lst: Optional[list]) -> None:
  result = '['
  while lst:
    result = result + str(lst.val) + (', ' if lst.next else '')
    lst = lst.next
  result = result + ']'
  return result

def compareLists(list1: Optional[ListNode], list2: list) -> bool:
  for v in list2:
    if list1.val != v:
      return False
    list1 = list1.next
  return list1 is None

def atIndex(lst: Optional[ListNode], index: int) -> Optional[ListNode]:
  if index < 0:
    return None
  for i in range(index):
    if lst is None:
      return None
    lst = lst.next
  return lst


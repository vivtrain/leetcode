from __future__ import annotations

class ListNode:
  def __init__(self, val=0, nxt=None):
    self.val = val
    self.next = nxt

def makeList(lst: Optional[list]) -> Optional[ListNode]:
  if not lst:
    return None
  head = ListNode(lst[0])
  node = head
  for i in range(1, len(lst)):
    node.next = ListNode(lst[i])
    node = node.next
  return head

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
  return True


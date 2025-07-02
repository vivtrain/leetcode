from __future__ import annotations
from typing import Optional, Any, List

class TreeNode:
  def __init__(self, val, left=None, right=None) -> None:
    self.val: Any = val
    self.left: Optional[TreeNode] = left
    self.right: Optional[TreeNode] = right

def insertBST(tree: Optional[TreeNode], val) -> TreeNode:
  while tree is not None:
    if val < tree.val:
      if tree.left == None:
        tree.left = TreeNode(val)
        return tree.left
      else:
        tree = tree.left
    elif val > tree.val:
      if tree.right == None:
        tree.right = TreeNode(val)
        return tree.right
      else:
        tree = tree.right
    else:
      return tree
  return TreeNode(val)

def makeBST(lst: List[Optional[TreeNode]]) -> Optional[TreeNode]:
  if len(lst) == 0:
    return None
  root = insertBST(None, lst[0])
  for i in range(1, len(lst)):
    insertBST(root, lst[i])
  return root

def makeTree(lst: List[Optional[TreeNode]]) -> Optional[TreeNode]:
  if not lst:
    return None
  for i,node in enumerate(lst):
    if node is None:
      continue
    left:  int = 2*i + 1
    right: int = 2*i + 2
    node.left  = lst[left]  if left  < len(lst) else None
    node.right = lst[right] if right < len(lst) else None
  return lst[0]

def printTree_recurse(prefix: str, tree: Optional[TreeNode], isLeft: bool) -> None:
  if tree:
    print(prefix + ('├──' if isLeft else '└──'), tree.val, sep='')
    printTree_recurse(prefix + ('│  ' if isLeft else '   '), tree.left, True)
    printTree_recurse(prefix + ('│  ' if isLeft else '   '), tree.right, False)
  else:
    print(prefix + ('├──' if isLeft else '└──'), '.', sep='')

def printTree(tree: Optional[TreeNode]):
  printTree_recurse('', tree, False)

